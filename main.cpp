#include "dna.h"

int main(int argv, char ** argc){
    bool first = true;
    DNA* dna;
    while(true){
        if(!first){
          string response;
          cout << "Enter the name of the file you would like to process: " << endl;
          cin >> response;
          DNA* dna = new DNA(response);
        }
        else {
          DNA* dna = new DNA(argc[1]);
          first = false;
        }

        int response;
        cout << "Enter 0 to exit and 1 to continue" << endl;
        cin >> response;
        if(response == 0){
          break;
        }
        else if(response == 1){
          continue;
        }
        else {
          cout << "ERROR: invalid response - terminating program..." << endl;
          break;
        }
    }
    delete dna;
    return 0;
}

// DNA* dna1 = new DNA();
// // declare ifstream instance to read through file
// ifstream inFile;
// inFile.open(argc[1]);
// // if it fails to open the file
// if(inFile.fail()){
//         cerr << "Error in opening file" << endl;
//         exit(1);
// }
// dna1->calculateStatistics(argc[1]);
// dna1->calculateSum(argc[1]);
// dna1->calculateMean(argc[1]);
// cout << "Sum: " << dna1->calculateSum(argc[1]) << endl;
// cout << "Mean: " << dna1->calculateMean(argc[1]) << endl;
// cout << "Variance: " << dna1->calculateVariance(argc[1]) << endl;
// cout << "Standard Deviation: " << dna1->calculateSTD(argc[1]) << endl;
// cout << "Number Of A: " << dna1->calculateProbabilityOfLetter(argc[1], 'a') << endl;
// cout << "Number Of GA: " << dna1->calculateProbabilityOfBigram(argc[1], "ga") << endl;

// #include "dna.h"

// int main(int argv, char ** argc){
//     while(true){
//         DNA* dna1 = new DNA();
//         // declare ifstream instance to read through file
//         ifstream inFile;
//         inFile.open("test");
//         // if it fails to open the file
//         if(inFile.fail()){
//                 cerr << "Error in opening file" << endl;
//                 exit(1);
//         }
//         // loop to count the number of nucleotides in the file
//         string item;
//         int count = 0;
//         string* nucleotides;
//         // exectutes as long not the end of the file
//         while(!inFile.eof()){
//                 inFile >> item;
//                 count++;
//         }
//         // assign size to the nucleotides array
//         nucleotides = new string[count];
//         inFile.close();
//         // open the file again - store file content into nucleotides array
//         inFile.open("test");
//         int i = 0;
//         string line;
//         while(!inFile.eof()){
//                 inFile >> line;
//                 // ensures the nucleotides are upper case
//                 for(int m = 0; line[m] != '\0'; ++m){
//                         line[m] = toupper(line[m]);
//                 }
//                 // assign the elements of the array
//                 nucleotides[i] = line;
//                 i++;
//         }
//         cout << "A " << dna1->calcProbOfOneNucleotide('a', count, nucleotides) << endl;
//         cout << "AAs " << dna1->calcProbOfNucleotidePair('c', 'a', count, nucleotides) << endl;
//         cout << "Sum: " << dna1->calcSum(nucleotides, count) << endl;
//         cout << "Mean Length: " << dna1->calcMean(nucleotides, count) << endl;
//         inFile.close();

//         cout << "Would you like to process another file? enter 0 for no and 1 for yes" << endl;
//         int response;
//         cin >>response;
//         if(response == 0){
//           delete nucleotides;
//           delete dna1;
//           break;
//         }
//         else if(response == 1){

//         }
//         else {
//           cout << "ERROR: invalid response - terminating program..." << endl;
//           break;
//         }
//       }
//         return 0;

// }
