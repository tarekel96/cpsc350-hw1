#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>
#include <cmath>
using namespace std;

class DNA {
  private:
       int totalNumberOfNucleotides;
       int totalNumberOfBigrams;
       int sum;
       float mean;
       float variance;
       float std;
       float probOfA;
       float probOfC;
       float probOfG;
       float probOfT;
       float probOfAA;
       float probOfAC;
       float probOfAG;
       float probOfAT;
       float probOfCA;
       float probOfCC;
       float probOfCG;
       float probOfCT;
       float probOfGA;
       float probOfGC;
       float probOfGG;
       float probOfGT;
       float probOfTA;
       float probOfTC;
       float probOfTG;
       float probOfTT;
  public:
        // default constructor
        DNA();
        // overloaded cosnstructor
        DNA(string file);
       // destructor
       ~DNA();
        // accessors
        int getTotalNumberOfNucleotides();
        int getTotalNumberOfBigrams();
        int getSum();
        float getMean();
        float getVariance();
        float getSTD();
        float getProbOfA();
        float getProbOfC();
        float getProbOfG();
        float getProbOfT();
        float getProbOfAA();
        float getProbOfAC();
        float getProbOfAG();
        float getProbOfAT();
        float getProbOfCA();
        float getProbOfCC();
        float getProbOfCG();
        float getProbOfCT();
        float getProbOfGA();
        float getProbOfGC();
        float getProbOfGG();
        float getProbOfGT();
        float getProbOfTA();
        float getProbOfTC();
        float getProbOfTG();
        float getProbOfTT();
        // mutators
        void setTotalNumberOfNucleotides(int count);
        void setTotalNumberOfBigrams(int count);
        void setSum(int newSum);
        void setMean(float newMean);
        void setSTD(float newStd);
        void setLength(int newLength);
        void setVariance(float newVariance);
        void setProbOfA(float pOfA);
        void setProbOfC(float pOfC);
        void setProbOfG(float pOfG);
        void setProbOfT(float pOfT);
        void setProbOfAA(float pOfAA);
        void setProbOfAC(float pOfAC);
        void setProbOfAG(float pOfAG);
        void setProbOfAT(float pOfAT);
        void setProbOfCA(float pOfCA);
        void setProbOfCC(float pOfCC);
        void setProbOfCG(float pOfCG);
        void setProbOfCT(float pOfCT);
        void setProbOfGA(float pOfGA);
        void setProbOfGC(float pOfGC);
        void setProbOfGG(float pOfGG);
        void setProbOfGT(float pOfGT);
        void setProbOfTA(float pOfTA);
        void setProbOfTC(float pOfTC);
        void setProbOfTG(float pOfTG);
        void setProbOfTT(float pOfTT);
        // math/helper functions for calculating statistics
        int calculateSum(string file);
        float calculateMean(string file);
        float calculateVariance(string file);
        float calculateSTD(string file);
        float calculateProbabilityOfLetter(string file, char letter);
        int calculateNumberOfBigrams(string file);
        float calculateProbabilityOfBigram(string file, string bigram);
        void calculateStatistics(string file);
        float generateRandomNumber();
        void generateGaussian(string file);
};
