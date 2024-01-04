#include <iostream> 
#include <vector> 


class node {
public:     int key;
      node* p; //указатель на пердыдущий элемент 
      int getKey()
      {
          return key;
      }

};

class Stack : public node {

private:

    int max_lenght = 30;     
    node* head; //указатель верхнего элемента 

public:

    Stack()
    {
        head = NULL;
    }
    Stack(int length)
    {
        head = NULL;
        max_lenght = length;
    }

    void _max_lenght_(int length)
    {
        max_lenght = length;
    }

    ~Stack() { //remove       
        while (head != NULL) {   
            node* temporal = head->p;     
            delete head;            
            head = temporal; 
    }
}

auto stackToVector(std::vector<int> vct)
{
    node* temporal = head;      
    while (temporal != NULL) {
        vct.push_back(temporal->key);  
        temporal = temporal->p;
    }             
    return vct;
}

int lenght()
{
    node* tempStart = head;
    int i = 0;
    while (head != NULL) {
        node* temporal = head->p;
        i += 1;            
        head = temporal;
    }
    head = tempStart;        
    return i;
}

void push(int data) { //Добравляем элемент в стэк    
    if (lenght() + 1 <= max_lenght) {       
        node* temoral = new node;// выделние динамической памяти 
    temoral->key = data;          
    temoral->p = head;       
    head = temoral;
}
 else std::cout << "Стэк переполнен, невозможен ввод. " << data << "\n";
    }

    void pop() { // удаление элемента из вершины стека    
        if (head == NULL) {    
            std::cout << "Стэк пуст, нечего удалять\n"; 
    }
 else {
     node* temporal = head;   
     std::cout << "Удалено: " << temporal->key << std::endl;      
     head = head->p;        
     delete temporal;
        }
    }

    int sum() { //поиск суммы элементов стека    
        node* temporal = head;     
        int sum = 0;     
        while (temporal != NULL) {      
            sum += temporal->key;     
            temporal = temporal->p; 
    }
    return sum;
    }

    void print() { //вывод списка на экран 
        bool flag = false;    
        node* temporal = head;   
        std::cout << "Сейчас в стэке:\n";   
        while (temporal != NULL) {
            std::cout << temporal->key << " ";      
            temporal = temporal->p;      
            flag = true;
        }         if (!flag) {
            std::cout << "Стэк пуст.\n";
        }
        std::cout << "\n";
    }

    void remove()
    {
        while (head != NULL) {
            node* temporal = head->p;        
            delete head;       
            head = temporal;
        }
    }

};

void menu(Stack st)
{
    std::cout << "Введите номер действия: \n 1.Вывод\n 2.Добавление элемента\n 3.Удалить\n 4.Удаление стэка\n 5.Сумма\n 6.Длина\n 7.Скопировать в вектор\n 8.Введение максимальной длины\n 9.Завершить?\n";
        std::vector<int> vct; 

        int number;    
        std::cin >> number;  
        switch (number)
    {
        case 1:       
        st.print();     
        break;     
        case 2:
            int input;       
            std::cout << "Введите добавляемое число:\n";    
            std::cin >> input;
        st.push(input);  
        menu(st);      
        break;   

        case 3:      
        st.pop();    
        menu(st);     
        break;    

        case 4:    
        st.remove();    
        menu(st);       
        break;   

        case 5:st.sum();  
        menu(st);      
        break;  

        case 6: st.lenght();  
        menu(st);      
        break;    

        case 7: st.stackToVector(vct);   
        menu(st);    
        break; 

        case 8:std::cout << "Введите максимальную длинну стэка.\n";    
            int length;     
            std::cin >> length;      
            st._max_lenght_(length);
        menu(st);      
        break; 

        case 9: break;   
        default:
            std::cout << "Некорректный ввод, попробуйте снова.\n";    
            menu(st);    
            break;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    Stack st;   
    st._max_lenght_(4); 
    st.push(1);   
    st.push(2);   
    st.push(3);  
    st.push(4);  
    st.push(5);   
    st.print();    
    st.pop();   
    st.pop();  
    st.print();
    std::cout << "Найденная сумма элементов стэка " << st.sum() << "\n";
    menu(st);  
    return 0;
}

