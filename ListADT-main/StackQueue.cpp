#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

// SimpleList Class
template <typename T>
class SimpleList
{
private:
    class Node
    {
        T data;
        Node* nextNode;
    public:
        Node(T data, Node* next);
        T getData();
        void setData(T data);
        Node* getNextNode();
        void setNextNode(Node* nextNode);
    };
    string name;

protected:
    void insertFront(T data);
    void insertEnd(T data);
    T deleteFront();

public:
    SimpleList();
    SimpleList(string Name);
    Node* firstNode;
    Node* lastNode;
    int size;
    string getName();
    virtual void push(T data) = 0;
    virtual T pop() = 0;
};

template <typename T> SimpleList<T>::Node::Node(T data, Node* next) { this->data = data; nextNode = next; }
template <typename T> T SimpleList<T>::Node::getData() { return data; }
template <typename T> void SimpleList<T>::Node::setData(T data) { this->data = data; }
template <typename T> typename SimpleList<T>::Node* SimpleList<T>::Node::getNextNode() { return nextNode; }
template <typename T> void SimpleList<T>::Node::setNextNode(Node* nextNode) { this->nextNode = nextNode; }

template <typename T> SimpleList<T>::SimpleList()
{
    firstNode = nullptr;
    lastNode = nullptr;
    size = 0;
}
template <typename T> SimpleList<T>::SimpleList(string name)
{
    firstNode = nullptr;
    lastNode = nullptr;
    size = 0;
    this->name = name;
}
template <typename T> void SimpleList<T>::insertFront(T data)
{
    if (size == 0)
    {
        Node* newNode = new Node(data, nullptr);
        firstNode = newNode;
        lastNode = newNode;
        size++;
    }
    else
    {
        Node* newNode = new Node(data, firstNode);
        firstNode = newNode;
        size++;
    }
    
}
template <typename T> void SimpleList<T>::insertEnd(T data)
{
    if (size == 0)
    {
        Node* newNode = new Node(data, nullptr);
        firstNode = newNode;
        lastNode = newNode;
        size++;
    }
    else
    {
        Node* newNode = new Node(data, nullptr);
        lastNode->setNextNode(newNode);
        lastNode = newNode;
        size++;
    }
}
template <typename T> T SimpleList<T>::deleteFront()
{
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        T returnData = firstNode->getData();
        Node* newFirstNode = firstNode->getNextNode();
        delete firstNode;
        firstNode = newFirstNode;
        size--;
        return returnData;
    }
}
template <typename T> string SimpleList<T>::getName() { return name; }

// Stack Class
template <typename T>
class Stack: public SimpleList<T>
{
public:
    Stack();
    Stack(string name); //Create a stack with an initial value
    void push(T data);
    T pop();
};

template <typename T> Stack<T>::Stack() :SimpleList<T>() {}
template <typename T> Stack<T>::Stack(string name) :SimpleList<T>(name) {}
template <typename T> void Stack<T>::push(T data) { this->insertFront(data); }
template <typename T> T Stack<T>::pop() { return this->deleteFront(); }

// Queue Class
template <typename T>
class Queue : public SimpleList<T>
{
public:
    Queue();
    Queue(string name);
    void push(T data);
    T pop();
};

template <typename T> Queue<T>::Queue() :SimpleList<T>() {}
template <typename T> Queue<T>::Queue(string name) :SimpleList<T>(name) {}
template <typename T> void Queue<T>::push(T data) { this->insertEnd(data); }
template <typename T> T Queue<T>::pop() { return this->deleteFront(); }

// MAIN FUNCTION
list<SimpleList<int>*> listSLi; // all integer stacks and queues
list<SimpleList<double>*> listSLd; // all double stacks and queues
list<SimpleList<string>*> listSLs; // all string stacks and queues

// Reads the user string input and initializes the file streams inputFile and outputFile
void ioFile(ifstream& inputFile, ofstream& outputFile);   

//Executes command according to the datatype of SimpleList
template <typename T> void process(string& command, string& id, list<SimpleList<T>*>& listSL, stringstream& lineStream, string& listType, ofstream& outputFile);

// Returns a pointer to the SimpleList datatype with the name "name" if found; Returns NULL if not
template <typename T> SimpleList<T>* findList(list<SimpleList<T>*> ls, string name);

int main()
{
    stringstream lineStream; // stringstream of a single command line
    string command; // stores first argument of the command line; can be create/push/pop
    string id;  // stores second argument of the command line; case-sensitive identifier of SimpleList object
    string listType; // stores third argument if command is "create"; can be stack/queue
    ifstream inputFile;
    ofstream outputFile;

    ioFile(inputFile, outputFile); // Open input/output files
    string line; // Read a single command line from input file
    while (getline(inputFile, line)) // Read a single line
    {
        outputFile << "PROCESSING COMMAND: " << line << "\n";
        lineStream << line; // Use stringstream
        while (lineStream >> command) // Read the first argument from the line as command
        {
            lineStream >> id; // Read the second argument from the line as identifier
            if (id[0] == 'i') { process<int>(command, id, listSLi, lineStream, listType, outputFile); }
            else if (id[0] == 'd') { process<double>(command, id, listSLd, lineStream, listType, outputFile); }
            else if (id[0] == 's') { process<string>(command, id, listSLs, lineStream, listType, outputFile); }
        }
        lineStream.clear(); // Clear the stringstream
    }
}

void ioFile(ifstream &inputFile, ofstream &outputFile)
{
    string inputFileName;
    string outputFileName;

    cout << "Enter the name of the input file: " << "\n";
    cin >> inputFileName;
    cout << "Enter the name of the output file: " << "\n";
    cin >> outputFileName;
    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
}
template <typename T> SimpleList<T>* findList(list<SimpleList<T>*> ls, string name)
{
    typename list<SimpleList<T>*>::iterator it = ls.begin();
    while (it != ls.end())
    {
        if ((*it)->getName() == name)
        {
            return *it;
        }
        else it++;
    }
    return NULL;
}
template <typename T> void process(string& command, string& id, list<SimpleList<T>*>& listSL, stringstream& lineStream, string& listType, ofstream& outputFile)
{
    if (command == "create")
    {
        if (findList(listSL, id) == NULL) // if an object with name NOT found from the list of objects
        {
            lineStream >> listType; // read the third argument as listType(stack/queue)
            if (listType == "stack") // if stack
            {
                Stack<T>* newStack = new Stack<T>(id); //create T type stack 
                listSL.push_back(newStack);
            }
            else if (listType == "queue") // if queue
            {
                Queue<T>* newQueue = new Queue<T>(id); //create T type queue 
                listSL.push_back(newQueue);
            }
        }
        else { outputFile << "ERROR: This name already exists!" << "\n"; } // if an object with name already exists
    }
    else if (command == "push") // if push
    {
        SimpleList<T>* founndList = findList(listSL, id);
        if (founndList == NULL) { outputFile << "ERROR: This name does not exist!" << "\n"; } // if an object with name already exists
        else
        {
            T data;
            lineStream >> data;
            founndList->push(data);
        }
    }
    else if (command == "pop") // if pop
    {
        SimpleList<T>* founndList = findList(listSL, id);
        if (founndList == NULL) { outputFile << "ERROR: This name does not exist!" << "\n"; } // if an object with name already exists
        else
        {
            if (founndList->size == 0) { outputFile << "ERROR: This list is empty!" << "\n"; } // if an object is empty
            else
            {
                outputFile << "Value popped: " << founndList->pop() << "\n";
            }
        }
    }
}
