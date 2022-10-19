
class Vehicle{

private:
    int maxSpeed;
protected:
    int numtyres;
public:
    string color;

    Vehicle()
    {
        cout <<"Vehicle default constructor"<<endl;
    }

    ~Vehicle()
    {
        cout <<"Vehicle default destructor"<<endl;
    }

};
