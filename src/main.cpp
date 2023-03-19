/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 7 de febrero de 2023, 14:02
 */


/**
 * This program reads from the stardard input, an integer n (number of elements) 
 * and a list of n pairs bigram-frequency. The pairs are stored in an array, 
 * and then it is sorted in decreasing order of frequency. After that, 
 * all the bigrams are changed to uppercase. The sorted array is finally shown 
 * in the stardard output. 
 * Running example:
 * > language1 < data/miniquijotebigrams.txt 
 */

using namespace std;

#include <iostream>
#include <string>

#include "Bigram.h"
#include "BigramFreq.h"
#include "ArrayBigramFreqFunctions.h"

int main(int argc, char* argv[]) {
    
    int n = 0;
    
    //cout << "Introduce the number of pairs BigramFreq to read: ";
    cin >> n;
    
    const int TAM = n;
    
    //cout << "We proceed to read the bigrams: " << endl;
    Bigram bi_aux;
    std::string text = "";
    int freq_aux = 0;
    
    BigramFreq array[TAM];
    for(int i = 0; i < n; i++){
        do{
            //cout << "Introduce the bigram(" << i << ") text (a pair of characters): " << endl;
            cin >> text;
        } while(text.length() != 2);
        
        bi_aux.at(0) = text[0];
        bi_aux.at(1) = text[1];
        array[i].setBigram(bi_aux);
        
        //cout << "Introduce the frequency of the bigram (an integer number): " << endl;
        cin >> freq_aux;
        
        array[i].setFrequency(freq_aux);
    }
    //cout << endl;
    //cout << "Original Array: " << endl;
    //printArrayBigramFreq(array, n);
    
    sortArrayBigramFreq(array, n);
    
    //cout << "Ordered Array: " << endl;
//    printArrayBigramFreq(array, n);
    
    toUpperArrayBigramFreq(array, n);
    
    //cout << "Final Ordered Array: " << endl;
    printArrayBigramFreq(array, n);
}

