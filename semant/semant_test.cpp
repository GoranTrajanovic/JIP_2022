#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <dirent.h>

using namespace std;

// opis: provjeravam je li prva linija ima syntax error at or near
// pre:	xstr1 je ulazni string
// post:	ako je u xstr1 syntax error onda makni sve unutar navodnika - filename
void checkSyntaxError(string& xstr1) {
	size_t pos1;
	pos1 = xstr1.find("syntax error at or near");
	if(pos1 != string::npos) {
// ako je onda na pocetku linije makni sve unutar navodnika
		xstr1 = xstr1.substr(1,xstr1.length());
		pos1 = xstr1.find('\"');
		xstr1 = "filename" + xstr1.substr(pos1+1, xstr1.length());
	}
}

// opis: provjeravam je li xstr4 ima filename (prva linija _class)
// pre:	xstr1 i xstr4 su ulazni stringovi
// post:	ako je u xstr1 _class onda makni u xstr4 filename
void checkFilename(string& xstr1, string& xstr4) {
	size_t pos1, pos2;
	pos1 = xstr1.find("_class");
	if(pos1 != string::npos) {
// ako je onda u trecoj liniji iza ime datoteke zamini sa filename
		pos2 = xstr4.find_first_not_of(" \t");
		xstr4 = xstr4.substr(0,pos2) + "filename";
	}
}

// opis: provjeravam je li druga linija pocinje sa _
// pre:	xstr1 i xstr2 su ulazni stringovi
// post:	ako je u xstr2 _ onda makni broj linije iz xstr2
void checkLineNo(string& xstr1, string& xstr2) {
	size_t pos2;
	pos2 = xstr2.find_first_not_of(" \t");
	if(xstr2[pos2] == '_') {
// ako je onda prethodnu zamini sa praznom da maknes brojeve linija
		xstr1 = "";
	} 
}

// opis: 	provjeravam je  linija ima poruku o gresci
// pre:		xstr1 je ulazni string, error je poruka o gresci
// post:	ako je u xstr1 gornji string onda makni sve prije dvotocke - filename
bool checkSemanticError(string& xstr1) {
	size_t pos1;
	pos1 = xstr1.find("Compilation halted due to static semantic errors.");
	if(pos1 != string::npos) {
		return true;
	}
	return false;
}


int main() {
// za citanje sadrzaja direktorija
	DIR* dir;
	struct dirent* ent;
// vektor sa imenima datoteka	
	vector<string> files;
// stringovi za obradu imena datotkea	
	string filename, filename_results, comm;
// za trazenje tocke	
	size_t pos, pos1, pos2;
	
// brisem i ponovo stvaram poddirektorij results	
	system("rm -r ./test_files/res");
	system("mkdir ./test_files/res");
// ako postoji folder test_files ulazim u njega	
	if ((dir = opendir ("test_files")) != NULL) {
// petlja koja prolazi kroz sve datoteke iz foldera	
		while ((ent = readdir (dir)) != NULL) {
			filename = string(ent->d_name);
// filtriram ono sta nisu datoteke			
			pos = filename.find(".");
			if(pos != string::npos && pos!=0) {
				filename = filename.substr(0,pos);
				if(find(files.begin(), files.end(), filename) == files.end()) { 
					files.push_back(filename);
				}
			}
		}
		closedir (dir);
	} else {
		/* could not open directory */
		perror ("");
		return EXIT_FAILURE;
	}
	

	cout << "provjeri sa pocetnim i sa potpunim semantickim analizatorom!" << endl;
	cout << "provjeri sa pocetnim i sa potpunim semantickim analizatorom!" << endl;
	cout << "provjeri sa pocetnim i sa potpunim semantickim analizatorom!" << endl;

	int nofiles=1;
	int nok=0;
	cout << endl << "ERRORS IN:" << endl;
// za svaku testnu datoteku	
	for(auto it : files) {
		nofiles++;
// ime testne datoteke		
		filename = ".//test_files//" + it;
// ime izlazne datoteke u folderu results		
		filename_results = ".//test_files//res//" + it;
// string sa naredbom za parsiranje i izlazom i stderr u datoteku
		comm = "./lexer "+filename+".cl | ./parser " + filename + ".cl | ./semant " + filename + ".cl >"+filename_results+".cool.myout 2>&1";
		system(comm.c_str());
		
// otvaram za usporedbu datoteku sa ispravnim izlazom i sa izlazom koji je gornja naredba stvorila
		ifstream out(filename+".cool.out");
		ifstream myout(filename_results+".cool.myout");
// otvaram datoteku u kojoj cu spremiti razlike		
		ofstream diff(filename_results+".diff");
		if( !diff ) {
			cout << "Error opening test file:" << filename_results << ".diff" << endl;
			return EXIT_FAILURE;
		}
		if( !myout ) {
			cout << "Error opening test file:" << filename_results << ".cool.myout" << endl;
			return EXIT_FAILURE;
		}
		if( !out ) {
			cout << "Error opening test file:" << filename << ".cool.out" << endl;
			return EXIT_FAILURE;
		}
// zapocinjem sa usporedbom		
		string mystr1, str1;
// prvo sve citam trazeci semanticke greske
		bool mySemErr = false;
		bool semErr = false;
		getline(myout, mystr1);
		do {
			if(checkSemanticError(mystr1)) 
				mySemErr=true;
			getline(myout, mystr1);
		} while(myout);
		getline(out, str1);
		do {
			if(checkSemanticError(str1)) 
				semErr=true;
			getline(out, str1);
		} while(out);
		if(mySemErr == true && semErr == true) {
			nok++;
		} else {
// prevrti datoteke na pocetak
			myout.clear();
			myout.seekg (0, ios::beg);
			out.clear();
			out.seekg (0, ios::beg);

			string mystr2, str2;
			string mystr3, str3;
			string mystr4, str4;
			int lineno=1;
// preskacem prvu liniju
			getline(myout, mystr1);
			getline(out, str1);
			getline(myout, mystr2);
			getline(out, str2);
			getline(myout, mystr3);
			getline(out, str3);
			getline(myout, mystr4);
			getline(out, str4);
// je li datoteka ispravna		
			bool ok = true;
			do {
				checkSyntaxError(mystr1);
				checkFilename(mystr1, mystr4);
				checkLineNo(mystr1, mystr2);
// isto za etalon
				checkSyntaxError(str1);
				checkFilename(str1, str4);
				checkLineNo(str1, str2);
				if(checkSemanticError(str1))
					semErr = true;

// usporedjujem			
				if(mystr1!=str1) {
					ok = false;
					diff << "error in line# " << lineno << endl;
					diff << "    parsed as: " << mystr1 << endl;
					diff << "    should be: " << str1 << endl;
				}
				lineno++;

// micem redove po jedan i citam novi			
				mystr1 = mystr2;
				str1 = str2;
				mystr2 = mystr3;
				str2 = str3;
				mystr3 = mystr4;
				str3 = str4;
				getline(myout, mystr4);
				getline(out, str4);
			} while(myout);
// je li izlazna datoteka ispravna		
			if(ok) {
				nok++;
			} else {
// ispisi redni broj i ime datoteke	
				cout << "    test file #"<< nofiles <<" : " << it << endl;
			} 
		}
		
		myout.close();
		out.close();
		diff.close();
	}	
	cout << "_____________________________" << endl << "Grade: " << nok << "/" << --nofiles << endl;
	return 0;
}
