template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    T temp = data[i];
    int p = parent(i);

    while(i > 0 && temp < data[p]) {
        data[i] = data[p];
        i = p;
        p = parent(i);
    }
    data[i] = temp;
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int size = this->size();

    while (true) {
        int l = left(i);
        if (l >= size) {
            return;
        }
        int smallest = l;
        int r = right(i);
        if (r < size && data[r] < data[l]) {
            smallest = r;
        }

        if (data[i] <= data[smallest]) {
            return;
        }

        T temp = data[i]; 
        data[i] = data[smallest];
        data[smallest] = temp;
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    int i = this->size() - 1;
    this->siftUp(i);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue = data[0];
    // TODO: Implement removing the root element.
    int i = size() - 1;
    data[0] = data[i];
    data.pop_back();
    if (size() > 1)
        siftDown(0);
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    if (index < size()) {
        siftUp(index);
        siftDown(index);
    }
}
