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
          cout << "ERROR: invalid response ~ terminating program..." << endl;
          break;
        }
    }
    delete dna;
    return 0;
}
