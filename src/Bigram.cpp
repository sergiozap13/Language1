/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   Bigram.cpp
 * @author: Sergio Zapata De la Hoz <sergiozap@correo.ugr.es>
 * 
 * Created on 5 de marzo de 2023, 13:44
 */

#include <cstring>

#include "Bigram.h"

Bigram::Bigram(const std::string& text) {
    if(text.size() == 2){
        this->_text[0] = text[0];
        this->_text[1] = text[1];
    } else {
        this->_text[0] = '_';
        this->_text[1] = '_';
    }
    
}

Bigram::Bigram(char first, char second) {
    this->_text[0] = first;
    this->_text[1] = second;
}

Bigram::Bigram(const char text[]){
    if(std::strlen(text) == 2){
        this->_text[0] = text[0];
        this->_text[1] = text[1];
    } else {
        this->_text[0] = '_';
        this->_text[1] = '_';
    }
}

std::string Bigram::getText() const{
    return this->_text;
}

std::string Bigram::toString() const{
    return this->_text;
}

const char& Bigram::at(int index) const{
    if(index < 0 || index > 1){
        throw std::out_of_range("const char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    } else{
        return _text[index];
    }     
}

char& Bigram::at(int index){
    if(index < 0 || index > 1){
        throw std::out_of_range("char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    } else{
        return _text[index];
    }
}

void Bigram::toUpper(){
//    int tam = bigram.getText().length();
//    
//    for (int i = 0; i < tam; i++){
//        if(islower(bigram.at(i))){
//            bigram.at(i) = std::toupper(bigram.at(i)); 
//        }
//    }
}

bool isValidCharacter(char character, const std::string& validCharacters){
    
    if (validCharacters.find(character) != std::string::npos){
        return true;
    }
    
    return false;
}

void toUpper(Bigram &bigram){
    int tam = bigram.getText().length();
    
    for (int i = 0; i < tam; i++){
        if(islower(bigram.at(i))){
            bigram.at(i) = std::toupper(bigram.at(i)); 
        }
    }
}

void toLower(Bigram &bigram){
    int tam = bigram.getText().length();
    
    for (int i = 0; i < tam; i++){
        if(isupper(bigram.at(i))){
            bigram.at(i) = std::tolower(bigram.at(i)); 
        }
    }
}