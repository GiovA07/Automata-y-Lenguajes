#ifndef AFND_H
#define AFND_H

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility> // Para std::pair
#include "../InterfaceFiniteAutomata.h"
#include "../deterministicAutomata/DeterministicFiniteAutomata.h"
#include <string>


using namespace std;

class NotDeterministicFiniteAutomata : public InterfaceFiniteAutomata {
private:
    set<int> k;                                     //Estados que hay en el automata
    set<int> alphabet;                              //el alfabeto
    map<pair<int,int>, set<int>> transitions;       //transiciones de un estado a otro. Toma un estado y un elemento (pair)
    int q0;                                         //estado inicial
    set<int> f;                                     //estados finales

public:
    NotDeterministicFiniteAutomata();
    //geters
    set<int> getK();
    set<int> getAlphabet();
    map<pair<int,int>, set<int>> getTransitions();
    int getInitialState();
    set<int> getFinalStates();
    //setters
    void setK(set<int> states);
    void setAlphabet(set<int> alphabet);
    void setTransitions(map<pair<int,int>, set<int>> transitions);
    void setInitialState(int q);
    void setFinalState(set<int> final);

    //functions
    void addTransition(int q, int r, int destination);
    void addState(int state);
    void addFinalState(int state);
    void addNewElementAlphabet(int element);
    set<int> getTransitionStates(pair<int, int> key);
    void readFile(string arch);
    void writeFile(string arch);
    void print();
    void menu();

    //FND U FND
    NotDeterministicFiniteAutomata unionAFDWithAFD(NotDeterministicFiniteAutomata AFND1, NotDeterministicFiniteAutomata AFND2);
    set<int> unionSets(set<int> a1, set<int> a2);
    map<pair<int,int>, set<int>> unionTransitions(map<pair<int,int>, set<int>> trans1, map<pair<int,int>, set<int>> trans2);



    DeterministicFiniteAutomata ndafToDfa();

private:
    set<int> lambdaClausure(set<int> state);
    set<int> move(set<int> conjState, int element);
    map<pair<int,int>, set<int>> getTransitionsWrite();
};

#endif
