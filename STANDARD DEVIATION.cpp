#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;

char option;
int temp, a, b, n;
double PopulationMean, SampleMean, PopulationSD, PopulationSD1, SampleSD, SampleSD1, Ptemp, Stemp;

	
int main(){
	
	cout << "How many? ";
	cin >> n;
	double arr[n];
	for(int i = 0; i < n; i++){
		cout << "input arr # " << i + 1 << ": ";
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}cout << endl;
	
	cout << "PopulatoionMean & SD [p] | SampleMean [s] & SD | Order [o]: ";
	cin >> option;
	switch(option){
		
		POPULATION:
			case 'p':
			case 'P':
				
				for(a = 0; a < n; a++){
					PopulationMean += arr[a];
				}
				PopulationMean /= n;
				
				for(a = 0; a < n; a++){
					PopulationSD1 = arr[a] - PopulationMean;
					Ptemp = PopulationSD1 * PopulationSD1;
					PopulationSD += Ptemp;
				}
				Ptemp = PopulationSD;
				Ptemp /= n;
				PopulationSD = sqrt(Ptemp);
				cout << "Mean:" << PopulationMean << endl << "SD:" << PopulationSD;
				break;
			
		SAMPLE:
			case 's':
			case 'S':
				for(a = 0; a < n; a++){
					SampleMean += arr[a];
				}
				SampleMean /= n;
				
				
				for(a = 0; a < n; a++){
					SampleSD1 = arr[a] - SampleMean;
					Stemp = SampleSD1 * SampleSD1;
					SampleSD += Stemp;
				}
				Stemp = SampleSD;
				Stemp /= (n-1);
				SampleSD = sqrt(Stemp);
				cout << "Mean:" << SampleMean << endl << "SD:" << SampleSD;
				break;
				
		ORDER:
			case 'o':
			case 'O':
				 for(a = 0; a < n; a++){
				 	for(b = a + 1; b < n; b++){
				 		if(arr[a] > arr[b]){
				 			temp = arr[b];
				 			arr[b] = arr[a];
				 			arr[a] = temp;
						}
					}
				}
				for(int i = 0; i < n; i++){
				cout << arr[i] << " ";
				}cout << endl;
				break;
				
		DEFAULT:
			default:
				break;
	}
	
	return 0;
}
