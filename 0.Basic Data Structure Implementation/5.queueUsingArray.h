

template <typename T>
class queueUsingArray{

    T *data;
    int front;
    int rear;
    int size; //size of queue.
    int capacity;

public:

    queueUsingArray(int totalSize)
    {
        data=new T[totalSize];
        front=-1;
        rear=-1;
        size=0;
        capacity=totalSize;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        return false;
    }

    T getfront()
    {
        if(front==-1)
        {
            cout <<"Queue Empty"<<endl;
            return 0;
        }
        return data[front];
    }

    //insert element into queue
    void enqueue(T element)
    {
        if(size==capacity)
        {
            T *newData = new T[capacity*2];
            int index=0;

            for(int i=front;i<capacity;i++)
            {
                newData[index]=data[i];
                index++;
            }

            for(int i=0;i<front;i++)
            {
                newData[index]=data[i];
                index++;
            }
            front=0;
            rear=capacity-1;
            delete [] data;
            data=newData;
            capacity*=2;
            //cout <<"Queue Full" <<endl;
            //return;
        }
        rear=(rear+1)%capacity;
        data[rear]=element;
        if(front == -1) //If first element is being inserted
        {
            front=0;
        }
        size++;
    }

    T dequeue()
    {
        if(front==-1)
        {
            cout <<"Queue empty"<<endl;
            return 0;
        }
        T ans=data[front];
        front=(front+1)%capacity;

        if(front == rear)//if queue will become zero then change to original state; I THINK THE CONDITION IS FALSE IT SHOULD BE IF SIZE == 0
        {
            front=-1;
            rear=-1;
        }
        size--;
        return ans;
    }



};

























