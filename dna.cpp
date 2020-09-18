#include "dna.h"
// DEFAULT CONSTRUCTOR
DNA::DNA(){
}
// OVERLOADED CONSTRUCTOR
DNA::DNA(string file){
  ifstream inFile;
  inFile.open(file);
  // checks to see if can open file - throws error otherwise
  if(inFile.fail()){
    cerr << "Error in opening file" << endl;
    exit(1);
  }
  inFile.close();
  calculateStatistics(file);
}
// DESTRUCTOR
DNA::~DNA(){
  cout << "Program terminated." << endl;
}
// ACCESSORS
int DNA::getTotalNumberOfNucleotides(){
  return totalNumberOfNucleotides;
}
int DNA::getTotalNumberOfBigrams(){
  return totalNumberOfBigrams;
}
int DNA::getSum(){
        return sum;
}
float DNA::getMean(){
        return mean;
}
float DNA::getVariance(){
  return variance;
}
float DNA::getSTD(){
        return std;
}
float DNA::getProbOfA(){
  return probOfA;
}
float DNA::getProbOfC(){
  return probOfC;
}
float DNA::getProbOfG(){
  return probOfG;
}
float DNA::getProbOfT(){
  return probOfT;
}
float DNA::getProbOfAA(){
  return probOfAA;
}
float DNA::getProbOfAC(){
  return probOfAC;
}
float DNA::getProbOfAG(){
  return probOfAG;
}
float DNA::getProbOfAT(){
  return probOfAT;
}
float DNA::getProbOfCA(){
  return probOfCA;
}
float DNA::getProbOfCC(){
  return probOfCC;
}
float DNA::getProbOfCG(){
  return probOfCG;
}
float DNA::getProbOfCT(){
  return probOfCT;
}
float DNA::getProbOfGA(){
  return probOfGA;
}
float DNA::getProbOfGC(){
  return probOfGC;
}
float DNA::getProbOfGG(){
    return probOfGG;
}
float DNA::getProbOfGT(){
  return probOfGT;
}
float DNA::getProbOfTA(){
  return probOfTA;
}
float DNA::getProbOfTC(){
  return probOfTC;
}
float DNA::getProbOfTG(){
  return probOfTG;
}
float DNA::getProbOfTT(){
  return probOfTT;
}
// MUTATORS
void DNA::setTotalNumberOfNucleotides(int count){
  totalNumberOfNucleotides = count;
}
void DNA::setTotalNumberOfBigrams(int count){
  totalNumberOfBigrams = count;
}
void DNA::setSum(int newSum){
        sum = newSum;
}
void DNA::setMean(float newMean){
        mean = newMean;
}
void DNA::setVariance(float newVariance){
  variance = newVariance;
}
void DNA::setSTD(float newStd){
        std = newStd;
}
void DNA::setProbOfA(float pOfA){
  probOfA = pOfA;
}
void DNA::setProbOfC(float pOfC){
  probOfC = pOfC;
}
void DNA::setProbOfG(float pOfG){
  probOfG = pOfG;
}
void DNA::setProbOfT(float pOfT){
  probOfT = pOfT;
}
void DNA::setProbOfAA(float pOfAA){
  probOfAA = pOfAA;
}
void DNA::setProbOfAC(float pOfAC){
  probOfAC = pOfAC;
}
void DNA::setProbOfAG(float pOfAG){
  probOfAG = pOfAG;
}
void DNA::setProbOfAT(float pOfAT){
  probOfAT = pOfAT;
}
void DNA::setProbOfCA(float pOfCA){
  probOfCA = pOfCA;
}
void DNA::setProbOfCC(float pOfCC){
  probOfCC = pOfCC;
}
void DNA::setProbOfCG(float pOfCG){
  probOfCG = pOfCG;
}
void DNA::setProbOfCT(float pOfCT){
  probOfCT = pOfCT;
}
void DNA::setProbOfGA(float pOfGA){
  probOfGA = pOfGA;
}
void DNA::setProbOfGC(float pOfGC){
  probOfGC = pOfGC;
}
void DNA::setProbOfGG(float pOfGG){
    probOfGG = pOfGG;
}
void DNA::setProbOfGT(float pOfGT){
  probOfGT = pOfGT;
}
void DNA::setProbOfTA(float pOfTA){
  probOfTA = pOfTA;
}
void DNA::setProbOfTC(float pOfTC){
  probOfTC = pOfTC;
}
void DNA::setProbOfTG(float pOfTG){
  probOfTG = pOfTG;
}
void DNA::setProbOfTT(float pOfTT){
  probOfTT = pOfTT;
}
// MATH/HELPER FUNCTIONS
int DNA::calculateSum(string file){
  ifstream inFile;
  inFile.open(file);
  int sum = 0;
  string currentElement;
  while(getline(inFile, currentElement)){
    sum += currentElement.length();
  }
  setSum(sum);
  inFile.close();
  return sum;
}
float DNA::calculateMean(string file){
  float mean;
  int sum = 0;
  int counter = 0;
  ifstream inFile;
  inFile.open(file);
  string currentElement;
  while(getline(inFile, currentElement)){
    sum += currentElement.length();
    counter++;
  }
  mean = (float)sum/counter;
  setMean(mean);
  inFile.close();
  return mean;
}
float DNA::calculateVariance(string file){
  float mean;
  int sum = 0;
  int counter = 0;
  ifstream inFile;
  inFile.open(file);
  string currentElement;
  while(getline(inFile, currentElement)){
    sum += currentElement.length();
    counter++;
  }
  mean = (float)sum/counter;
  inFile.close();
  inFile.open(file);
  string line;
  float variance;
  while(getline(inFile, line)){
    variance += ( ((float)line.length() - mean) * ((float)line.length() - mean) )/counter;
  }
  setVariance(variance);
  inFile.close();
  return variance;
}
float DNA::calculateSTD(string file){
  float variance = calculateVariance(file);
  double std;
  std = sqrtf(variance);
  setSTD(std);
  return std;
}
// PROBABILITY OF A SINGLE NUCLEOTIDE
float DNA::calculateProbabilityOfLetter(string file, char letter){
  letter = toupper(letter);
  int letterCount = 0;
  ifstream inFile;
  inFile.open(file);
  string line;
  while(getline(inFile, line)){
    for(int i = 0; i < line.length(); ++i){
      if(line[i] == letter){
        letterCount++;
      }
    }
  }
  int sum = calculateSum(file);
  float probability = (float)letterCount/sum;
  inFile.close();
  return probability;
}
int DNA::calculateNumberOfBigrams(string file){
  ifstream inFile;
  int counter = 0;
  string line;
  inFile.open(file);
  while(getline(inFile, line)){
    // if it is an even line of nucelotides
    if(line.length() % 2 == 0){
      counter += (line.length() / 2);
    }
    else {
      counter += (line.length() - 1) / 2;
      counter += 1;
    }
  }
  inFile.close();
  setTotalNumberOfBigrams(counter);
  return counter;
}
// PROBABILITY OF A BIGRAM
float DNA::calculateProbabilityOfBigram(string file, string bigram){
  int totalNumberOfBigrams = getTotalNumberOfBigrams();
  // cout << "In nucleotide func: " << totalNumberOfBigrams << endl;
  int countOfBigram = 0;
  // converts the bigram argument to upper case
  transform(bigram.begin(), bigram.end(),bigram.begin(), ::toupper);
  // string bigram2 = "";
  // bigram2.push_back(bigram[1]);
  // bigram2.push_back(bigram[0]);
  // cout << "BIGRAM 2: " << bigram2 << endl;
  ifstream inFile;
  inFile.open(file);
  string line;
  string currentBigram;
  while(getline(inFile, line)){
    if(line.length() % 2 == 0){
      for(int i = 0; i < line.length(); ++i, ++i){
        currentBigram = "";
        currentBigram.push_back(line[i]);
        currentBigram.push_back(line[i + 1]);
        if(currentBigram == bigram){
          countOfBigram++;
        }
      }
    }
    else{
      for(int i = 1; i < line.length() - 1; ++i, ++i){
        currentBigram = "";
        currentBigram.push_back(line[i]);
        currentBigram.push_back(line[i + 1]);
        if(currentBigram == bigram){
          countOfBigram++;
        }
      }
      currentBigram = "";
      currentBigram.push_back(line[0]);
      currentBigram.push_back(line[line.length() - 1]);
      if(currentBigram == bigram){
        countOfBigram++;
      }
    }
  }
  inFile.close();
  return (float)countOfBigram/totalNumberOfBigrams;
}
void DNA::calculateStatistics(string file){
  // the functions below set their values to their fields in their function definitions
  calculateNumberOfBigrams(file);
  calculateSum(file);
  calculateMean(file);
  calculateVariance(file);
  calculateSTD(file);
  // calc probabilities and assign them to their value fields
  setProbOfA(calculateProbabilityOfLetter(file, 'a'));
  setProbOfC(calculateProbabilityOfLetter(file, 'c'));
  setProbOfG(calculateProbabilityOfLetter(file, 'g'));
  setProbOfT(calculateProbabilityOfLetter(file, 't'));
  setProbOfAA(calculateProbabilityOfBigram(file, "aa"));
  setProbOfAC(calculateProbabilityOfBigram(file, "ac"));
  setProbOfAG(calculateProbabilityOfBigram(file, "ag"));
  setProbOfAT(calculateProbabilityOfBigram(file, "at"));
  setProbOfCA(calculateProbabilityOfBigram(file, "ca"));
  setProbOfCC(calculateProbabilityOfBigram(file, "cc"));
  setProbOfCG(calculateProbabilityOfBigram(file, "cg"));
  setProbOfCT(calculateProbabilityOfBigram(file, "ct"));
  setProbOfGA(calculateProbabilityOfBigram(file, "GA"));
  setProbOfGC(calculateProbabilityOfBigram(file, "GC"));
  setProbOfGG(calculateProbabilityOfBigram(file, "GG"));
  setProbOfGT(calculateProbabilityOfBigram(file, "GT"));
  setProbOfTA(calculateProbabilityOfBigram(file, "TA"));
  setProbOfTC(calculateProbabilityOfBigram(file, "TC"));
  setProbOfTG(calculateProbabilityOfBigram(file, "TG"));
  setProbOfTT(calculateProbabilityOfBigram(file, "TT"));
  ofstream outFile;
  outFile.open("yourname.out");
  outFile << "Tarek El-Hajjaoui\nCPSC 350 - 03\nAssignment 2\n09/22/2020\nStatistics:   " << endl;
  outFile << "The Sum of the length of the DNA strings is:                              " << getSum() << endl;
  outFile << "The Mean of the length of the DNA strings is:                             " << getMean() << endl;
  outFile << "The Variance of the length of the DNA strings is:                         " << getVariance() << endl;
  outFile << "The Standard Deviation of the length of the DNA strings is:               " << getSTD() << endl;
  outFile << "Probability of A:                                                         " << getProbOfA() << endl;
  outFile << "Probability of C:                                                         " << getProbOfC() << endl;
  outFile << "Probability of G:                                                         " << getProbOfG() << endl;
  outFile << "Probability of T:                                                         " << getProbOfT() << endl;
  outFile << "Probability of AA:                                                        " << getProbOfAA() << endl;
  outFile << "Probability of AC:                                                        " << getProbOfAC() << endl;
  outFile << "Probability of AG:                                                        " << getProbOfAG() << endl;
  outFile << "Probability of AT:                                                        " << getProbOfAT() << endl;
  outFile << "Probability of CA:                                                        " << getProbOfCA() << endl;
  outFile << "Probability of CC:                                                        " << getProbOfCC() << endl;
  outFile << "Probability of CG:                                                        " << getProbOfCG() << endl;
  outFile << "Probability of CT:                                                        " << getProbOfCT() << endl;
  outFile << "Probability of GA:                                                        " << getProbOfGA() << endl;
  outFile << "Probability of GC:                                                        " << getProbOfGC() << endl;
  outFile << "Probability of GG:                                                        " << getProbOfGG() << endl;
  outFile << "Probability of GT:                                                        " << getProbOfGT() << endl;
  outFile << "Probability of TA:                                                        " << getProbOfTA() << endl;
  outFile << "Probability of TC:                                                        " << getProbOfTC() << endl;
  outFile << "Probability of TG:                                                        " << getProbOfTG() << endl;
  outFile << "Probability of TT:                                                        " << getProbOfTT() << endl;
  outFile.close();
  generateGaussian("yourname.out");
}
// generates a random number between 0 and 1
float DNA::generateRandomNumber(){
  return ((float)rand() / RAND_MAX);
}
// GAUSSIAN DISTRIBUTION LOGIC
void DNA::generateGaussian(string file){
  ofstream outFile;
  outFile.open(file, ios::out | ios::app);
  float a = generateRandomNumber();
  float b = generateRandomNumber();
  float c;
  float d;
  c = sqrt(-2 * log(a)) * cos(M_PI * b);
  cout << "variance " << getVariance() << endl;
  cout << "mean " << getMean() << endl;
  d = (variance * c) + mean;
  cout << "D before: " << d << endl;
  d = floor(d);
  cout << "D after: " << d << endl;
  cout << "A: " << a << endl;
  cout << "B: " << b << endl;
  cout << "C: " << c << endl;
  // length of the string is D for each of the 1000 elements
  // add handling if the read file has incorrect input
  int totalNumberOfLetters = d * 1000;
  cout << "total number of letters: " << totalNumberOfLetters << endl;
  int numberOfA = floor(getProbOfA() * totalNumberOfLetters);
  int numberOfC = floor(getProbOfC() * totalNumberOfLetters);
  int numberOfG = floor(getProbOfG() * totalNumberOfLetters);
  int numberOfT = floor(getProbOfT() * totalNumberOfLetters);
  int numberOfAA = floor(getProbOfAA() * totalNumberOfLetters);
  int numberOfAC = floor(getProbOfAC() * totalNumberOfLetters);
  int numberOfAG = floor(getProbOfAG() * totalNumberOfLetters);
  int numberOfAT = floor(getProbOfAT() * totalNumberOfLetters);
  int numberOfCA = floor(getProbOfCA() * totalNumberOfLetters);
  int numberOfCC = floor(getProbOfCC() * totalNumberOfLetters);
  int numberOfCG = floor(getProbOfCG() * totalNumberOfLetters);
  int numberOfCT = floor(getProbOfCT() * totalNumberOfLetters);
  int numberOfGA = floor(getProbOfGA() * totalNumberOfLetters);
  int numberOfTA = floor(getProbOfTA() * totalNumberOfLetters);
  cout << "NUMBER OF A: " << numberOfA << endl;
  cout << "NUMBER OF AA: " << numberOfAA << endl;
  cout << "NUMBER OF AC: " << numberOfAC << endl;
  cout << "NUMBER OF AG: " << numberOfAG << endl;
  cout << "NUMBER OF AT: " << numberOfAT << endl;
  cout << "NUMBER OF TA: " << numberOfTA << endl;
  cout << "NUMBER OF GA: " << numberOfGA << endl;
  cout << "NUMBER OF CA: " << numberOfCA << endl;
  int D = (int)d;
  float countAA = 0;
  float countAC = 0;
  float countAG = 0;
  float countAT = 0;
  float countCA = 0;
  float countCC = 0;
  float countCG = 0;
  float countCT = 0;
  bool flip = false;
  for(int i = 0; i < 1000; ++i){
      for(int j = 0; j < D; ++j){
        if(countAA < numberOfAA){
          if(j == D - 1){
            outFile << "A";
            countAA = countAA + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "A";
            countAA = countAA + 0.5;
            flip = false;
          }
          else {
            outFile << "AA";
            countAA++;
            ++j;
          }
        }
        else if(countAC < numberOfAC){
          if(j == D - 1){
            outFile << "A";
            countAC = countAC + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "C";
            countAC = countAC + 0.5;
            flip = false;
          }
          else {
            outFile << "AC";
            countAC++;
            ++j;
          }
        }
        else if(countAG < numberOfAG){
          if(j == D - 1){
            outFile << "A";
            countAG = countAG + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "G";
            countAG = countAG + 0.5;
            flip = false;
          }
          else {
            outFile << "AG";
            countAG++;
            ++j;
          }
        }
        else if(countCA < numberOfCA){
          if(j == D - 1){
            outFile << "C";
            countCA = countCA + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "A";
            countCA = countCA + 0.5;
            flip = false;
          }
          else {
            outFile << "CA";
            countCA++;
            ++j;
          }
        }
        else if(countCC < numberOfCC){
          if(j == D - 1){
            outFile << "C";
            countCC = countCC + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "C";
            countCC = countCC + 0.5;
            flip = false;
          }
          else {
            outFile << "CC";
            countCC++;
            ++j;
          }
        }
        else if(countCG < numberOfCG){
          if(j == D - 1){
            outFile << "C";
            countCG = countCG + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "G";
            countCG = countCG + 0.5;
            flip = false;
          }
          else {
            outFile << "CG";
            countCG++;
            ++j;
          }
        }
        else if(countCT < numberOfCT){
          if(j == D - 1){
            outFile << "C";
            countCT = countCT + 0.5;
            flip = true;
          }
          else if(flip == true){
            outFile << "T";
            countCT = countCT + 0.5;
            flip = false;
          }
          else {
            outFile << "CT";
            countCT++;
            ++j;
          }
        }
        // else if(countCA < numberOfCA){
        //   if(j == D - 1){
        //     outFile << "A";
        //     countCA = countCA + 0.5;
        //     flip = true;
        //   }
        //   else if(flip == true){
        //     outFile << "C";
        //     countCA = countCA + 0.5;
        //     flip = false;
        //   }
        //   else {
        //     outFile << "CA";
        //     countAG++;
        //     ++j;
        //   }
        // }
      }
      outFile << "\n";
  }
  // cout << "COUNT OF AA: " << countAA << endl;
  // if(D % 2 == 0){
  //   for(int i = 0; i < 1000; ++i){
  //     for(int j = 0; j < numberOfAA; ++j, ++j){
  //       for(int k = 0; k < D; ++k){
  //         outFile << "AA";
  //       }
  //     outFile << "\n";
  //     }
  //   }
  // } else {
  //   for(int i = 0; i < 1000; ++i){
  //       for(int k = 0; k < D; ++k){
  //         if(k == D - 1){
  //           outFile << "A";
  //         }
  //         else {
  //           outFile << "AA";
  //           countAA++;
  //         }
  //       }
  //     outFile << "\n";
  //     }
  // }

  cout << "D: " << d << endl;
  // cout << "Number of AA: " << numberOfAA << endl;

  outFile.close();
}
// int DNA::calcSum(string arr[], int arrLength){
//   int sum = 0;
//   for(int i = 0; i < arrLength; ++i){
//     string currentElement = arr[i];
//     for(int j = 0; j < currentElement.length(); ++j){
//       sum++;
//     }
//   }
//   return sum;
// }
// double DNA::calcMean(string arr[], int arrLength){
//   int lengthArray[arrLength];
//   for(int i = 0; i < arrLength; ++i){
//     int currentElement = arr[i].length();
//     lengthArray[i] = currentElement;
//   }
//   int sum = 0;
//   for(int j = 0; j < arrLength; ++j){
//     sum += lengthArray[j];
//   }
//   double mean;
//   mean = (double)sum/arrLength;
//   return mean;
// }
// int DNA::calcNumberOfNucleotides(string file){
//         ifstream MyReadFile(file);
//         string input;
//         int i = 0;
//         while(MyReadFile >> input){
//             i++;
//         }
//         MyReadFile.close();
//         return i;
// }
// float DNA::calcProbOfOneNucleotide(char nucleotide, int arrLength, string arr[]){
//   nucleotide = toupper(nucleotide);
//   int counter = 0;
//   for(int j = 0; j < arrLength; ++j){
//     string currentNucleotide = arr[j];
//     for(int k = 0; k < currentNucleotide.size(); ++k){
//       if(currentNucleotide[k] == nucleotide){
//         counter++;
//       }
//     }
//   }
//   int total = arrLength * 2;
//   float probability;
//   probability = (float)counter/total;
//   return probability;
// }
// float DNA::calcProbOfNucleotidePair(char nucleotide1, char nucleotide2, int arrLength, string arr[]){
//   int counter = 0;
//   string pairOne = "";
//   string pairTwo = "";
//   nucleotide1 = toupper(nucleotide1);
//   nucleotide2 = toupper(nucleotide2);
//   string n1 = ToStr(nucleotide1);
//   string n2 = ToStr(nucleotide2);
//   pairOne.append(n1);
//   pairOne.append(n2);
//   pairTwo.append(n2);
//   pairTwo.append(n1);
//   for(int i = 0; i < arrLength; ++i){
//     if(arr[i] == pairOne || arr[i] == pairTwo){
//       counter++;
//     }
//   }
//   float probability;
//   probability = (float)counter/arrLength;
//   return probability;
// }
