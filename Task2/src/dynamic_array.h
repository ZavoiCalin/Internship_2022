#include <iostream>
#include <string>

class DynamicStringArray {
    private:
        std::string *dynamicArray;
        int size;

    public:
        DynamicStringArray() {
            dynamicArray = nullptr;
            size = 0;
        }

        DynamicStringArray(const DynamicStringArray &copy) {

            dynamicArray = copy.dynamicArray;

            int crtSize = getSize();
            int copySize = copy.size;
            size = copy.size;

            for (int i = 0; i < size; i++) {
                dynamicArray[i] = copy.dynamicArray[i];
            }
        
        }

        DynamicStringArray &operator=(const DynamicStringArray &assigned) {
            
            if(this != &assigned) {

                int crtSize = getSize();
                crtSize = assigned.size;

                for (int i = 0; i < size; i++) {
                    dynamicArray[i] = assigned.dynamicArray[i];
                }
    
            }

            return *this;
        }

        ~DynamicStringArray() {

            delete[] this;

            std::cout<<"Destructor called\n";
        }
        
        int getSize() {
            return size;
        }
        
        void addEntry(std::string e) {
            int crtSize = getSize();
            int newSize = crtSize + 1;
            std::string *newDynamicArray = new std::string[newSize];

            for (int i = 0; i < size; i++) {
                newDynamicArray[i] = dynamicArray[i];
            }

            newDynamicArray[crtSize] = e;
            crtSize++;

            delete[] dynamicArray;

            dynamicArray = newDynamicArray;
        }
        
        bool deleteEntry(std::string e) {
            int crtSize = getSize();
            int newSize = crtSize - 1;

            for (int i = 0; i < crtSize; i++) {
                if (dynamicArray[i] == e) {
                int depl = 0;

                std::string *newDynamicArray = new std::string[newSize];

                for (int j = 0; j < newSize; j++) {
                    if (dynamicArray[j] == e) {
                        newDynamicArray[j] = dynamicArray[j + 1];
                        depl++;
                    }
                    else {
                        newDynamicArray[j] = dynamicArray[j + depl];
                    }
                }

                    crtSize--;
                    delete[] dynamicArray;
                    dynamicArray = newDynamicArray;

                

                    return true;
                }
            }

            return false;
        }

        std::string *getEntry(int i) {
            int crtSize = getSize();

            if (i < crtSize) {
                return &dynamicArray[i];
            }
            
            return nullptr;
            
        }

        void display() {
            for(int i = 0; i < getSize(); i++) {
                std::cout<<dynamicArray[i]<<"\n";
            }
        }
};