/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
C++ Review HW1
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

int main (int argc, char** argv){
  ofstream myfile ("PranavSaravanan.out");
  while(true){

    ////ifstream used to take input from file
    string fileName;
    cout << "Please enter in the file name: " << endl;
    cin >> fileName;
    ifstream infile;
    infile.open(fileName);
    if (!infile) {
      cerr << "Unable to open file";
      exit(1);
  }
    //Variables for total count of nucleotides and total number of each nucleotide individually, and count for line numbers as well from file
    string str;
    int count = 0;
    int countA = 0;
    int countT = 0;
    int countC = 0;
    int countG = 0;
    int lineNum = 0;

    //variables for the count of each nucleotide bigram
    int countAA = 0;
    int countCA = 0;
    int countTA = 0;
    int countGA = 0;
    int countAC = 0;
    int countCC = 0;
    int countTC = 0;
    int countGC = 0;
    int countAT = 0;
    int countCT = 0;
    int countTT = 0;
    int countGT = 0;
    int countAG = 0;
    int countCG = 0;
    int countTG = 0;
    int countGG = 0;

    //getting count of each indivudal nucleotides, line number, and total number of nucleotides using while and for loops, getting the count of each nucleotide bigram using while and for loops
    while (getline(infile, str)) {
      lineNum++;
      for (int i = 0; i < str.length(); i++){

        if ((str.at(i) == ('A'))||((str.at(i) == ('a')))){
          count++;
          countA++;
            if ((str.at(i+1) == ('A'))||((str.at(i+1) == ('a')))){
              countAA++;
            }
            else if ((str.at(i+1) == ('T'))||((str.at(i+1) == ('t')))){
              countAT++;
            }
            else if ((str.at(i+1) == ('C'))||((str.at(i+1) == ('c')))){
              countAC++;
            }
            else if ((str.at(i+1) == ('G'))||((str.at(i+1) == ('g')))){
              countAG++;
            }
        }

        else if ((str.at(i) == ('T'))||((str.at(i) == ('t')))){
          count++;
          countT++;
            if ((str.at(i+1) == ('A'))||((str.at(i+1) == ('a')))){
              countTA++;
            }
            else if ((str.at(i+1) == ('T'))||((str.at(i+1) == ('t')))){
              countTT++;
            }
            else if ((str.at(i+1) == ('C'))||((str.at(i+1) == ('c')))){
              countTC++;
            }
            else if ((str.at(i+1) == ('G'))||((str.at(i+1) == ('g')))){
              countTG++;
            }
        }

        else if ((str.at(i) == ('C'))||((str.at(i) == ('c')))){
          count++;
          countC++;
            if ((str.at(i+1) == ('A'))||((str.at(i+1) == ('a')))){
              countCA++;
            }
            else if ((str.at(i+1) == ('T'))||((str.at(i+1) == ('t')))){
              countCT++;
            }
            else if ((str.at(i+1) == ('C'))||((str.at(i+1) == ('c')))){
              countCC++;
            }
            else if ((str.at(i+1) == ('G'))||((str.at(i+1) == ('g')))){
              countCG++;
          }
        }

        else if ((str.at(i) == ('G'))||((str.at(i) == ('g')))){
          count++;
          countG++;
            if ((str.at(i+1) == ('A'))||((str.at(i+1) == ('a')))){
              countGA++;
            }
            else if ((str.at(i+1) == ('T'))||((str.at(i+1) == ('t')))){
              countGT++;
            }
            else if ((str.at(i+1) == ('C'))||((str.at(i+1) == ('c')))){
              countGC++;
            }
            else if ((str.at(i+1) == ('G'))||((str.at(i+1) == ('g')))){
              countGG++;
        }
      }
      i++;
    }
  }
  infile.close();

    //Having to multiply all stats by 2 since i was incremented twice in the for loop
    countA = countA * 2;
    countT = countT * 2;
    countC = countC * 2;
    countG = countG * 2;
    count = count * 2;

    //calculations for mean, variance, and standard deviation
    float mean = float(count)/ float(lineNum);
    float variance = 0;
    string string1;
    ifstream inputfile;
    inputfile.open(fileName);
    if(inputfile.is_open()){
      while (getline(inputfile, string1)) {
        variance += (pow(((string1.length()-1)-mean), 2))/lineNum;
      }
    }
    inputfile.close();

    float standDev = sqrt(variance);

    //calculations for probability of each single nucelotide
    float probA = (float(countA)/float(count));
    float probT = (float(countT)/float(count));
    float probC = (float(countC)/float(count));
    float probG = (float(countG)/float(count));


    //calculations for the nucleotide bigram probabilities
    float probAA = (float(countAA)/float(16));
    float probCA = (float(countCA)/float(16));
    float probTA = (float(countTA)/float(16));
    float probGA = (float(countGA)/float(16));
    float probAC = (float(countAC)/float(16));
    float probCC = (float(countCC)/float(16));
    float probTC = (float(countTC)/float(16));
    float probGC = (float(countGC)/float(16));
    float probAT = (float(countAT)/float(16));
    float probCT = (float(countCT)/float(16));
    float probTT = (float(countTT)/float(16));
    float probGT = (float(countGT)/float(16));
    float probAG = (float(countAG)/float(16));
    float probCG = (float(countCG)/float(16));
    float probTG = (float(countTG)/float(16));
    float probGG = (float(countGG)/float(16));

    //Calculations for the Guassian Distribution
    float a = ((double) rand() / (RAND_MAX));
	  float b = ((double) rand() / (RAND_MAX));
    float C = (sqrt(-2*log(a)))*(cos(2*(M_PI)*b));
    float D = (standDev * C) + mean;

    //outputing to a file
    if(myfile.is_open()){
      myfile << "Pranav Saravanan" << endl;
      myfile << "Student id: 2341335" << endl;
      myfile << "Email: saravanan@chapman.edu" << endl;
      myfile << "CPSC 350-01" << endl;
      myfile << "C++ Review HW1" << endl;
      myfile << endl;
      myfile << "A: " << countA << endl;
      myfile << "T: " << countT << endl;
      myfile << "C: " << countC << endl;
      myfile << "G: " << countG << endl;
      myfile << endl;
      myfile << "Sum: " << count << endl;
      myfile << "Line Numbers " << lineNum << endl;
      myfile << "Mean: " << mean << endl;
      myfile << endl;
      myfile << "Probability of A: " << probA << endl;
      myfile << "Probability of T: " << probT << endl;
      myfile << "Probability of C: " << probC << endl;
      myfile << "Probability of G: " << probG << endl;
      myfile << endl;
      myfile << "Probability of AA: "<< probAA << endl;
      myfile << "Probability of AC: "<< probAC << endl;
      myfile << "Probability of AT: "<< probAT << endl;
      myfile << "Probability of AG: "<< probAG << endl;
      myfile << endl;
      myfile << "Probability of CA: "<< probCA << endl;
      myfile << "Probability of CC: "<< probCC << endl;
      myfile << "Probability of CT: "<< probCT << endl;
      myfile << "Probability of CG: "<< probCG << endl;
      myfile << endl;
      myfile << "Probability of TA: "<< probTA << endl;
      myfile << "Probability of TC: "<< probTC << endl;
      myfile << "Probability of TT: "<< probTT << endl;
      myfile << "Probability of TG: "<< probTG << endl;
      myfile << endl;
      myfile << "Probability of GA: "<< probGA << endl;
      myfile << "Probability of GC: "<< probGC << endl;
      myfile << "Probability of GT: "<< probGT << endl;
      myfile << "Probability of GG: "<< probGG << endl;
      myfile << endl;
      myfile << "Variance: " << variance << endl;
      myfile << "Standard Deviation: " << standDev << endl;

      //Gaussian Distribution, using the calculated probabilities and D to calculate the maximum number of reccomened probabilities of each nucleotide to output for 1000 lines to the output file
      for(int i = 0; i < 1000; i++){

        float numA = D * probA;
        float numC = D * probC;
        float numT = D * probT;
        float numG = D * probG;

        int countGauA;
        int countGauC;
        int countGauT;
        int countGauG;

        for(int k=1; k< D; k++){
          int randomNum = (rand() % 4) +1;
          if(randomNum == 1){
            if(countGauA >= numA){
              myfile << 'C';
              countGauC++;
            }
            else{
              myfile << 'A';
              countGauA++;
            }
          }
          if(randomNum == 2){
            if(countGauC >= numC){
              myfile << 'A';
              countGauA++;
            }
            else{
              myfile << 'C';
              countGauC++;
            }
          }
          if(randomNum == 3){
            if(countGauT >= numT){
              myfile << 'G';
              countGauG++;
            }
            else{
              myfile << 'T';
              countGauT++;
            }
          }
          if(randomNum == 4){
            if(countGauG >= numG){
              myfile << 'T';
              countGauT++;
            }
            else{
              myfile << 'G';
              countGauG++;
            }
          }
        }
        myfile << endl;
      }
      myfile.close();
    }

    //reseting all the variables for loop
    probA = 0;
    probC = 0;
    probT = 0;
    probG = 0;
    standDev = 0;

    //asking if while loop needs to be run again
    char answer;
    cout << "Would you like to process another list? (Y/N)" << endl;
    cin >> answer;
    if(answer == ('Y') || answer == ('y')){
      continue;
    }
    else{
      break;
    }

  }
}
