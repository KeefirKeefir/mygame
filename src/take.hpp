// ownership transfer from one raw pointer to another
template <typename T>
T* take(T* &ptr) {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}