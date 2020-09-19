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
  int numberOfAA = floor(getProbOfAA() * (totalNumberOfLetters * 0.5));
  int numberOfAC = floor(getProbOfAC() * (totalNumberOfLetters * 0.5));
  int numberOfAG = floor(getProbOfAG() * (totalNumberOfLetters * 0.5));
  int numberOfAT = floor(getProbOfAT() * (totalNumberOfLetters * 0.5));
  int numberOfCA = floor(getProbOfCA() * (totalNumberOfLetters * 0.5));
  int numberOfCC = floor(getProbOfCC() * (totalNumberOfLetters * 0.5));
  int numberOfCG = floor(getProbOfCG() * (totalNumberOfLetters * 0.5));
  int numberOfCT = floor(getProbOfCT() * (totalNumberOfLetters * 0.5));
  int numberOfGA = floor(getProbOfGA() * (totalNumberOfLetters * 0.5));
  int numberOfGC = floor(getProbOfGC() * (totalNumberOfLetters * 0.5));
  int numberOfGG = floor(getProbOfGG() * (totalNumberOfLetters * 0.5));
  int numberOfGT = floor(getProbOfGT() * (totalNumberOfLetters * 0.5));
  int numberOfTA = floor(getProbOfTA() * (totalNumberOfLetters * 0.5));
  int numberOfTC = floor(getProbOfTC() * (totalNumberOfLetters * 0.5));
  int numberOfTG = floor(getProbOfTG() * (totalNumberOfLetters * 0.5));
  int numberOfTT = floor(getProbOfTT() * (totalNumberOfLetters * 0.5));
  cout << "NUMBER OF AA: " << numberOfAA << endl;
  cout << "NUMBER OF AC: " << numberOfAC << endl;
  cout << "NUMBER OF AG: " << numberOfAG << endl;
  cout << "NUMBER OF AT: " << numberOfAT << endl;
  cout << "NUMBER OF TA: " << numberOfTA << endl;
  cout << "NUMBER OF GA: " << numberOfGA << endl;
  cout << "NUMBER OF CA: " << numberOfCA << endl;
  int D = (int)d;
  int countA = 0;
  int countC = 0;
  int countG = 0;
  int countT = 0;
  float countAA = 0;
  float countAC = 0;
  float countAG = 0;
  float countAT = 0;
  float countCA = 0;
  float countCC = 0;
  float countCG = 0;
  float countCT = 0;
  float countGA = 0;
  float countGC = 0;
  float countGG = 0;
  float countGT = 0;
  float countTA = 0;
  float countTC = 0;
  float countTG = 0;
  float countTT = 0;
  bool flip = false;
  bool flipLine = false;

  cout << "D: " << d << endl;

  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < D; ++j, ++j){
      // case 1 - AA
      if(countAA != numberOfAA){
        if(D % 2 != 0){
          if(flip){
            outFile << "A";
            flip = false;
            flipLine = true;
            countAA++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "A";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "AA";
            flipLine = false;
            countAA++;
          }
          else {
            outFile << "AA";
            countAA++;
          }
        }
        else {
          outFile << "AA";
          countAA++;
        }
      }
      // case 2 - AC
      else if(countAC != numberOfAC){
        if(D % 2 != 0){
          if(flip){
            outFile << "C";
            flip = false;
            flipLine = true;
            countAC++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "A";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "AC";
            flipLine = false;
            countAC++;
          }
          else {
            outFile << "AC";
            countAC++;
          }
        }
        else {
          outFile << "AC";
          countAC++;
        }
      }
      // case 3 - AG
      else if(countAG != numberOfAG){
        if(D % 2 != 0){
          if(flip){
            outFile << "G";
            flip = false;
            flipLine = true;
            countAG++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "A";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "AG";
            flipLine = false;
            countAG++;
          }
          else {
            outFile << "AG";
            countAG++;
          }
        }
        else {
          outFile << "AG";
          countAG++;
        }
      }
      // case 4 - AT
      else if(countAT != numberOfAT){
        if(D % 2 != 0){
          if(flip){
            outFile << "T";
            flip = false;
            flipLine = true;
            countAT++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "A";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "AT";
            flipLine = false;
            countAT++;
          }
          else {
            outFile << "AT";
            countAT++;
          }
        }
        else {
          outFile << "AT";
          countAT++;
        }
      }
      // case 5 - CA
      else if(countCA != numberOfCA){
        if(D % 2 != 0){
          if(flip){
            outFile << "A";
            flip = false;
            flipLine = true;
            countCA++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "A";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "CA";
            flipLine = false;
            countCA++;
          }
          else {
            outFile << "CA";
            countCA++;
          }
        }
        else {
          outFile << "CA";
          countCA++;
        }
      }
      // case 6 - CC
      else if(countCC != numberOfCC){
        if(D % 2 != 0){
          if(flip){
            outFile << "C";
            flip = false;
            flipLine = true;
            countCC++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "C";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "CC";
            flipLine = false;
            countCC++;
          }
          else {
            outFile << "CC";
            countCC++;
          }
        }
        else {
          outFile << "CC";
          countCC++;
        }
      }
      // case 7 - CG
      else if(countCG != numberOfCG){
        if(D % 2 != 0){
          if(flip){
            outFile << "G";
            flip = false;
            flipLine = true;
            countCG++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "C";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "CG";
            flipLine = false;
            countCG++;
          }
          else {
            outFile << "CG";
            countCG++;
          }
        }
        else {
          outFile << "CG";
          countCG++;
        }
      }
      // case 8 - CT
      else if(countCT != numberOfCT){
        if(D % 2 != 0){
          if(flip){
            outFile << "T";
            flip = false;
            flipLine = true;
            countCT++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "C";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "CT";
            flipLine = false;
            countCT++;
          }
          else {
            outFile << "CT";
            countCT++;
          }
        }
        else {
          outFile << "CT";
          countCT++;
        }
      }
      // case 9 - GA
      else if(countGA != numberOfGA){
        if(D % 2 != 0){
          if(flip){
            outFile << "A";
            flip = false;
            flipLine = true;
            countGA++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "G";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "GA";
            flipLine = false;
            countGA++;
          }
          else {
            outFile << "GA";
            countGA++;
          }
        }
        else {
          outFile << "GA";
          countGA++;
        }
      }
      // case 10 - GC
      else if(countGC != numberOfGC){
        if(D % 2 != 0){
          if(flip){
            outFile << "C";
            flip = false;
            flipLine = true;
            countGC++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "G";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "GC";
            flipLine = false;
            countGC++;
          }
          else {
            outFile << "GC";
            countGC++;
          }
        }
        else {
          outFile << "GC";
          countGC++;
        }
      }
      // case 11 - GG
      else if(countGG != numberOfGG){
        if(D % 2 != 0){
          if(flip){
            outFile << "G";
            flip = false;
            flipLine = true;
            countGG++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "G";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "GG";
            flipLine = false;
            countGG++;
          }
          else {
            outFile << "GG";
            countGG++;
          }
        }
        else {
          outFile << "GG";
          countGG++;
        }
      }
      // case 12 - GT
      else if(countGT != numberOfGT){
        if(D % 2 != 0){
          if(flip){
            outFile << "T";
            flip = false;
            flipLine = true;
            countGT++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "G";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "GT";
            flipLine = false;
            countGT++;
          }
          else {
            outFile << "GT";
            countGT++;
          }
        }
        else {
          outFile << "GT";
          countGT++;
        }
      }
      // case 13 - TA
      else if(countTA != numberOfTA){
        if(D % 2 != 0){
          if(flip){
            outFile << "A";
            flip = false;
            flipLine = true;
            countTA++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "T";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "TA";
            flipLine = false;
            countTA++;
          }
          else {
            outFile << "TA";
            countTA++;
          }
        }
        else {
          outFile << "TA";
          countTA++;
        }
      }
      // case 14 - TC
      else if(countTC != numberOfTC){
        if(D % 2 != 0){
          if(flip){
            outFile << "C";
            flip = false;
            flipLine = true;
            countTC++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "T";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "TC";
            flipLine = false;
            countTC++;
          }
          else {
            outFile << "TC";
            countTC++;
          }
        }
        else {
          outFile << "TC";
          countTC++;
        }
      }
      // case 15 - TG
      else if(countTG != numberOfTG){
        if(D % 2 != 0){
          if(flip){
            outFile << "G";
            flip = false;
            flipLine = true;
            countTG++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "T";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "TG";
            flipLine = false;
            countTG++;
          }
          else {
            outFile << "TG";
            countTG++;
          }
        }
        else {
          outFile << "TG";
          countTG++;
        }
      }
      // case 16 - TT
      else if(countTT != numberOfTT){
        if(D % 2 != 0){
          if(flip){
            outFile << "T";
            flip = false;
            flipLine = true;
            countTT++;
            continue;
          }
          if(j == D - 1 && flipLine == false){
            outFile << "T";
            flip = true;
          }
          else if(j == D - 1 && flipLine == true){
            outFile << "TT";
            flipLine = false;
            countTT++;
          }
          else {
            outFile << "TT";
            countTT++;
          }
        }
        else {
          outFile << "TT";
          countTT++;
        }
      }
      else {
        break;
      }
    }
    outFile << "\n";
  }
  outFile.close();
}
// for(int i = 0; i < 1000; ++i){
//     for(int j = 0; j < D; ++j){
//       if(countAA < numberOfAA){
//         if(j == D - 1){
//           outFile << "A";
//           countAA = countAA + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "A";
//           countAA = countAA + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "AA";
//           countAA++;
//           ++j;
//         }
//       }
//       else if(countAC < numberOfAC){
//         if(j == D - 1){
//           outFile << "A";
//           countAC = countAC + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "C";
//           countAC = countAC + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "AC";
//           countAC++;
//           ++j;
//         }
//       }
//       else if(countAG < numberOfAG){
//         if(j == D - 1){
//           outFile << "A";
//           countAG = countAG + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "G";
//           countAG = countAG + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "AG";
//           countAG++;
//           ++j;
//         }
//       }
//       else if(countCA < numberOfCA){
//         if(j == D - 1){
//           outFile << "C";
//           countCA = countCA + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "A";
//           countCA = countCA + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "CA";
//           countCA++;
//           ++j;
//         }
//       }
//       else if(countCC < numberOfCC){
//         if(j == D - 1){
//           outFile << "C";
//           countCC = countCC + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "C";
//           countCC = countCC + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "CC";
//           countCC++;
//           ++j;
//         }
//       }
//       else if(countCG < numberOfCG){
//         if(j == D - 1){
//           outFile << "C";
//           countCG = countCG + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "G";
//           countCG = countCG + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "CG";
//           countCG++;
//           ++j;
//         }
//       }
//       else if(countCT < numberOfCT){
//         if(j == D - 1){
//           outFile << "C";
//           countCT = countCT + 0.5;
//           flip = true;
//         }
//         else if(flip == true){
//           outFile << "T";
//           countCT = countCT + 0.5;
//           flip = false;
//         }
//         else {
//           outFile << "CT";
//           countCT++;
//           ++j;
//         }
//       }
//     }
//     outFile << "\n";
// }
