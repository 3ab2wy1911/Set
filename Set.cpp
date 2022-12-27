#include <bits/stdc++.h>
using namespace std;
//________________________________________________
template<typename T>
class Set {
    T*arr;
    int Size , VirtualSize;
public:
    explicit Set()
    {
        Size = 0;
        VirtualSize=5;
        arr = new T [Size];
    }
//________________________________________________
    ~Set()
    {
        delete [] arr;
    }
//________________________________________________
    void insert(T item)
    {
        if (!find(item))
            if (Size < VirtualSize)
            {
                arr [Size++] = item;
            }
            else
            {
                VirtualSize *= 2;
                T* newArr = new T [VirtualSize];
                for (int i=0;i<VirtualSize;i++)
                {
                    newArr[i]='\0';
                }
                for (int i = 0; i< Size ; i++)
                {
                    newArr [i] = arr[i] ;
                }
                newArr [Size++] = item;
                delete[] arr;
                arr = newArr;
            }
        sort(arr,arr+Size);
    }
//________________________________________________
    T &operator[](int index)
    {
        if (index >= Size )
        {
            throw (" Index out of range ");
        }
        return this -> arr[index];
    }
//________________________________________________
    void erase(T item)
    {
       if(!find(item))
       {
           cout<<"This element is not in this set\n";
       }
       else {
           int index;
           int index2=-1;
           for (int i = 0; i < Size; i++) {
               if (arr[i] == item) {
                   index =i;
                   break;
               }
           }
           Size--;
           T* newArr;
           newArr = new T [VirtualSize];
           for (int i=0;i<Size;i++)
           {
               for(int j=0;j<Size+1;j++)
               {
                   if (index!=j and index2<j)
                   {
                       newArr[i]=arr[j];
                       index2 = j;
                       break;
                   }
               }
           }
           delete [] arr;
           arr =newArr;
           sort (arr,arr+Size);
       }
    }
//________________________________________________
    bool find(T item)
    {
        bool check =false;
       for (int i=0;i<Size;i++)
       {
           check = (item == arr[i]);
           if (check) break;
       }
       return check;
    }
//________________________________________________
    int size() const
    {
        return Size;
    }
//________________________________________________
    T* get_array()
    {
        return arr;
    }
//________________________________________________
   bool operator==(const Set<T>& AnotherSet)
    {
        if (size() != AnotherSet.size())
        {
            return false;
        }
        for (int i =0 ;i < size(); i++)
        {
            if(arr[i] != AnotherSet.arr[i] )
            {
                return false;
            }
        }
        return true;
    }
//________________________________________________
    bool operator!=(const Set<T>& AnotherSet)
    {

        return !(*this == AnotherSet);
    }
};
//===============================================================================
//=================================================================================

int main() {
    Set<int> first;
    first.insert(2);
    first.insert(1);
    first.insert(2);
    first.insert(1);
    first.insert(2);
    first.insert(10236541);
    first.insert(3);
    for (int i=0 ;i<first.size();i++)
    {
        cout<<first[i]<<" ";
    }
    cout<<endl;
    if (first.find(1))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    first.erase(12);
    first.erase(3);
    for (int i=0 ;i<first.size();i++)
    {
        cout<<first[i]<<" ";
    }
    cout<<endl;
    Set<int> second;
    Set<int> Third;
    for (int i=0;i<5;i++) {
        Third.insert(i);
        second.insert(i);
    }
    if (first == second)
    {
        cout<<"first vector == second one\n";
    }
    if (first != second)
    {
        cout<<"first vector != second one\n";
    }
    if (Third == second)
    {
        cout<<"Third vector == second one\n";
    }
    if (Third != second)
    {
        cout<<"Third vector != second one\n";
    }
}
