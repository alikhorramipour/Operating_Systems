#include <iostream>
#include <stdlib.h>

using namespace std;


void printHistogram(int *hist){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < hist[i]; j++)
            cout << "*";
        cout << endl;
    }
}


int main(int argc, char *argv[]) {

	srand(time(NULL));

	int hist[25] = {0}; // used to store results
	int counter = 0;
	int rnd = 0;

	for(int i = 0; i < 300; i++){
		for (int j = 0; j < 12; j++) {
			rnd = rand() % 101;
			//cout << "Generated number is: " << rnd << endl;
			if(rnd >= 49)
				counter++;
			else
				counter--;
			//cout << "Counter number is: " << counter << " and the pointer would be: " << counter + 12 << endl;
		}

		hist[counter + 12]++;
		counter = 0;
	}

	/*for(int i = 0; i < 25; i++)
		cout << hist[i] << endl;*/

    printHistogram(hist);

	return 0;

}
