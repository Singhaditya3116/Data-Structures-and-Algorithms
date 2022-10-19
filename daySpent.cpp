#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<typeinfo>
using namespace std;

int convertToInt(string a){
    //cout <<"A : "<<a<<endl;
    stringstream ss;
    ss << a;
    int num;
    ss >> num;
    return num;
}

int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob)
{
    unordered_map<int,int> m;
    m = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    int arriveAliceMonth = convertToInt(arriveAlice.substr(0,2));
    int arriveAliceDate = convertToInt(arriveAlice.substr(3,2));

    int leaveAliceMonth = convertToInt(leaveAlice.substr(0,2));
    int leaveAliceDate = convertToInt(leaveAlice.substr(3,2));

    int arriveBobMonth = convertToInt(arriveBob.substr(0,2));
    int arriveBobDate = convertToInt(arriveBob.substr(3,2));

    int leaveBobMonth = convertToInt(leaveBob.substr(0,2));
    int leaveBobDate = convertToInt(leaveBob.substr(3,2));


    if((arriveBobMonth >= arriveAliceMonth && arriveBobMonth <= leaveAliceMonth)||(arriveAliceMonth >= arriveBobMonth && arriveAliceMonth <= leaveBobMonth))
    {
        int startMatchDate = 0;
        int startMatchMonth = 0;
        if(arriveAliceMonth == arriveBobMonth)
        {
            startMatchMonth = arriveAliceMonth;
            startMatchDate = max(arriveAliceDate,arriveBobDate);
        }
        else
        {
            startMatchMonth = max(arriveAliceMonth,arriveBobMonth);
            startMatchDate = arriveAliceMonth > arriveBobMonth ? arriveAliceDate : arriveBobDate;
        }

        int endMatchDate = 0;
        int endMatchMonth = 0;
        if(leaveAliceMonth == leaveBobMonth)
        {
            endMatchMonth = leaveAliceMonth;
            endMatchDate = min(leaveAliceDate,leaveBobDate);
        }
        else
        {
            endMatchMonth = min(leaveAliceMonth,leaveBobMonth);
            endMatchDate = leaveAliceMonth < leaveBobMonth ? leaveAliceDate : leaveBobDate;
        }

        //cout <<"Start Date :" << startMatchDate <<" "<<startMatchMonth<<endl;
        //cout <<"End match Date :"<<endMatchDate << " "<<endMatchMonth<<endl;


        int daySpentTogether = 0;

        while(true)
        {
            if(startMatchMonth == endMatchMonth)
            {
                if(startMatchDate > endMatchDate){
                    return 0;
                }
                daySpentTogether += endMatchDate - startMatchDate + 1;
                break;
            }
            else
            {
                int dayRemainingInThatMonth = (m[startMatchMonth] - startMatchDate) + 1;
                daySpentTogether += dayRemainingInThatMonth;
                startMatchDate=1;
                startMatchMonth++;
            }
        }

        return daySpentTogether;
    }
    else{
        return 0;
    }


    return 0;
}

int main(){

    string arriveAlice,leaveAlice,arriveBob,leaveBob;
    cin >> arriveAlice >> leaveAlice>>arriveBob >> leaveBob;

    cout << countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob);

}
