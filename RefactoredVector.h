//
// Created by Rostik on 3/4/2024.
//

#ifndef HOMEWORK_2_REFACTOREDVECTOR_H
#define HOMEWORK_2_REFACTOREDVECTOR_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

template <typename T>
class RefactoredVector : public std::vector<T> {
public:
    RefactoredVector() : names_(std::make_shared<std::vector<std::string>>()) {}

    RefactoredVector(const RefactoredVector& other) : std::vector<T>(other), names_(other.names_) {}

    ~RefactoredVector() = default;

    void push_back(const T& obj, const std::string& name) {
        CopyNames();

        std::vector<T>::push_back(obj);
        names_->push_back(name);
    }

    std::pair<const T&, const std::string&> operator[](int index) const {
        if (index >= std::vector<T>::size())
            throw std::out_of_range("Index is out of range");

        return { std::vector<T>::operator[](index), (*names_)[index] };
    }

    const T& operator[](const std::string& name) const {
        auto iter = std::find(names_->begin(), names_->end(), name);
        if (iter == names_->end())
            throw std::invalid_argument(name + " is not found in RefactoredVector");

        return std::vector<T>::operator[](iter - names_->begin());
    }

private:
    void CopyNames() {
        if (names_.use_count() == 1)
            return;

        names_ = std::make_shared<std::vector<std::string>>(*names_);
    }

private:
    std::shared_ptr<std::vector<std::string>> names_;
};

#endif //HOMEWORK_2_REFACTOREDVECTOR_H
