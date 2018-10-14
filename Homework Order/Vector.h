class Vector {
private:
    int *array;
    int size;
    int numberOfElements;
public:
    Vector();
    int get(int index);
    void insert(int value);
    void remove(int value);
    void sort();
    int length();
    void merge(Vector &vector2);
    void display();
    int extractMax();
    void increase(int oldValue, int newValue);

};

