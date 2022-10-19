#include <bits/stdc++.h>
using namespace std;

class CDMA {
	public:
	int** wtable;
	int** copy;
	int* channel_sequence;

	void setUp(int data[], int num_stations) {
		int n=num_stations;
		wtable = new int* [n];

		for(int i=0;i<n;i++)
			wtable[i]=new int[n];

		copy = new int* [n];
		for(int i=0;i<n;i++)
			copy[i]=new int[n];

		buildWalshTable(num_stations, 0, num_stations - 1, 0, num_stations - 1, false);

		showWalshTable(num_stations);

		for (int i = 0; i < num_stations; i++) {
			for (int j = 0; j < num_stations; j++) {
				copy[i][j] = wtable[i][j];
				wtable[i][j] *= data[i];
			}
		}

		channel_sequence = new int[n];

		for (int i = 0; i < num_stations; i++) {
			for (int j = 0; j < num_stations; j++) {
				channel_sequence[i] += wtable[j][i];
			}
		}
	}

	void listenTo(int sourceStation, int num_stations) {
		int innerProduct = 0;
		for (int i = 0; i < num_stations; i++) {
			innerProduct += copy[sourceStation][i] * channel_sequence[i];
		}

		int k=innerProduct/num_stations;

		if(k==1)
			cout<<"The data received from station "<<sourceStation+1<<" is: "<<k<<endl;
		else if(k==-1)
			cout<<"The data received from station "<<sourceStation+1<<" is: 0"<<endl;
		else
			cout<<"Station "<<sourceStation+1<<" is idle, it didn't send any data\n";
	}

	//building walsh table
	int buildWalshTable(int len, int i1, int i2, int j1,int j2, bool isBar) {
		if (len == 2) {
			if (!isBar) {
				wtable[i1][j1] = 1;
				wtable[i1][j2] = 1;
				wtable[i2][j1] = 1;
				wtable[i2][j2] = -1;
			}
			else {
				wtable[i1][j1] = -1;
				wtable[i1][j2] = -1;
				wtable[i2][j1] = -1;
				wtable[i2][j2] = +1;
			}
			return 0;
		}

		int midi = (i1 + i2) / 2;
		int midj = (j1 + j2) / 2;

		buildWalshTable(len / 2, i1, midi, j1, midj, isBar);
		buildWalshTable(len / 2, i1, midi, midj + 1, j2, isBar);
		buildWalshTable(len / 2, midi + 1, i2, j1, midj, isBar);
		buildWalshTable(len / 2, midi + 1, i2, midj + 1, j2, !isBar);

		return 0;
	}

	void showWalshTable(int num_stations) {
		cout<<"................Displaying walsh table..................\n";
		//cout<<endl;
		for (int i = 0; i < num_stations; i++) {
			for (int j = 0; j < num_stations; j++) {
				cout<<wtable[i][j]<<"  ";
			}
			cout<<"\n";
		}
		cout<<"----------------------------------------------------------\n";
	}
};

int main() {
	cout<<"-------------------------------CDMA Implementation------------------------\n";

	int num_stations;
	cout<<"Enter no of stations\n";

	cin>>num_stations;
	//data bits corresponding to each station
	cout<<"Press 1 if station is sending bit 1\n";
	cout<<"Press -1 if station is sending bit 0\n";
	cout<<"Press 0 if station is idle\n";
	int* data=new int[num_stations];
	for(int i=0;i<num_stations;i++){
		cout<<"enter for station "<<i+1<<endl;
		cin>>data[i];
	}

	CDMA channel;

	channel.setUp(data, num_stations);

	// station you want to listen to
	cout<<"Enter station no you want to listen to\n";
	int sourceStation;
	cin>> sourceStation;

	channel.listenTo(sourceStation-1, num_stations);
	return 0;
}
