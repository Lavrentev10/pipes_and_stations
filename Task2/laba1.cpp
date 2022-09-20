#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>

//#include <sstream>


using namespace std;

auto add_pipe(){

    vector<string> newpipe;

    string newpname, newplen, newpdim, newpstat;

    cout << "Name > ";
    getline(cin, newpname);

    int lencheck;
    while(true){
    lencheck = 0;
    cout << "Length > ";
    getline(cin, newplen);

    for (int x = 0; x < newplen.length(); x ++){
            if (isdigit(newplen[x]) == false){
                lencheck += 1;
                break;
            }
        }
    if (lencheck == 0){
        break;
    } else {
        cout << "\n! Lenght should be an integer\n" << endl;
    }
    }

    int dimcheck;
    while(true){
    dimcheck = 0;
    cout << "Diameter > ";
    getline(cin, newpdim);

    for (int x = 0; x < newpdim.length(); x ++){
            if (isdigit(newpdim[x]) == false){
                dimcheck += 1;
                break;
            }
        }
    if (dimcheck == 0){
        break;
    } else {
        cout << "\n! Diameter should be an integer\n" << endl;
    }
    }
    bool statusyn = false;
    while(true){
        cout << "Repair status [Y/N] > ";
        getline(cin, newpstat);

        if (newpstat == "y" || newpstat == "n" || newpstat == "Y" || newpstat == "N"){
            statusyn = true;
        }

        if (statusyn == true){
            if (newpstat == "y" ||newpstat == "Y"){
                newpstat = "y";
            } else if (newpstat == "n" || newpstat == "N"){
                newpstat = "n";
            }
            break;
        } else {
            cout << "\n! Invalid value\n" << endl;
        }
    }

    //ADDING TO VECTORS

    newpipe.push_back(newpname);
    newpipe.push_back(newplen);
    newpipe.push_back(newpdim);
    newpipe.push_back(newpstat);

    /*for (string i: newpipe) {
    cout << i << ' ' << endl;
    }*/

    //cout << pname[0] << endl;

    //struct retpipe{string pipe1, pipe2, pipe3;};


    //return retpipe{newpname, newplen, newpdim};
    
    return newpipe;

}

auto add_css(){

    vector<string> newcs;
    string newcsname, workshops, workshopson, efficiency;

    cout << "Name > ";
    getline(cin, newcsname);

    int shopcheck;
    while(true){
    shopcheck = 0;
    cout << "Number of Workshops > ";
    getline(cin, workshops);

    for (int x = 0; x < workshops.length(); x ++){
            if (isdigit(workshops[x]) == false){
                shopcheck += 1;
                break;
            }
        }
    if (shopcheck == 0){
        break;
    } else {
        cout << "\n! Number of Workshops should be an integer\n" << endl;
    }
    }

    int shoponcheck;
    while(true){
    shoponcheck = 0;
    cout << "Number of workshops in work> ";
    getline(cin, workshopson);

    for (int x = 0; x < workshopson.length(); x ++){
            if (isdigit(workshopson[x]) == false){
                shoponcheck += 1;
                break;
            }
        }
    if (shoponcheck == 0){
        break;
    }else {
        cout << "\n! Number of Workshops in work should be an integer\n" << endl;
    }
    }

    int effcheck;
    while(true){
    effcheck = 0;
    cout << "Efficiency > ";
    getline(cin, efficiency);

    for (int x = 0; x < efficiency.length(); x ++){
            if (isdigit(efficiency[x]) == false){
                effcheck += 1;
                break;
            }
        }
    if (effcheck == 0){
        break;
    } else {
        cout << "\n! Efficiency should be an integer\n" << endl;
    }
    }

    newcs.push_back(newcsname);
    newcs.push_back(workshops);
    newcs.push_back(workshopson);
    newcs.push_back(efficiency);

    return newcs;
}

void print_list(vector<vector<string>> infotoprint){

    //cout << infotoprint.size() << " | " << infotoprint[0].size() << endl;
    cout << "\nPipes:" << endl;

    for (int i = 0; i < infotoprint[0].size(); i++){
        cout << i+1 << ") " << infotoprint[0][i] << ", " << infotoprint[1][i] <<
        ", "<< infotoprint[2][i] << ", " << infotoprint[3][i] << ";" << endl;
    }

    cout << "\nCompressor stations:" << endl;
    for (int i = 0; i < infotoprint[4].size(); i++){
        cout << i+1 << ") " << infotoprint[4][i] << ", " << infotoprint[5][i] <<
        ", "<< infotoprint[6][i] << ", " << infotoprint[7][i] << ";" << endl;
    }
}

auto edit_pipe(vector<vector<string>> pipestoedit){

    string newpipename,newpipelen,newpipedim, newpipestat,
    pipenum, paramnum;
    int editcheck;
    bool editswitch = false;

    //cout << pipestoedit[0].size() << endl;
    while (true)
    {
        editcheck = 0;
        cout << "Pipe number > ";
        getline(cin, pipenum);

        for (int x = 0; x < pipenum.length(); x ++){
            if (isdigit(pipenum[x]) == false){
                editcheck += 1;
                break;
            }
        }
        //cout << "editcheck" << editcheck << endl;

        if (editcheck == 0){
            //cout << "test1 + " << endl;
            //cout << stoi(pipenum) << endl;
            if (stoi(pipenum) >= 1 && stoi(pipenum) <= pipestoedit[0].size()){
                editswitch = true;
                break;
            }
    
        }
        //cout << editswitch << endl;
    }

    cout << pipestoedit[0][stoi(pipenum)-1] << ", " << pipestoedit[1][stoi(pipenum)-1] << ", "
    << pipestoedit[2][stoi(pipenum)-1] << ", " << pipestoedit[3][stoi(pipenum)-1] << ";" << endl;

    while (true)
    {
        cout << "1 - Name\n2 - Length\n3 - Diameter\n4 - Status of repair" << endl;
        editcheck = 0;
        cout << "Paramenetr number > ";
        getline(cin, paramnum);

        for (int x = 0; x < paramnum.length(); x ++){
            if (isdigit(paramnum[x]) == false){
                editcheck += 1;
                break;
            }
        }

        if (editcheck == 0){
            if (stoi(paramnum) >= 1 && stoi(paramnum) <= 4){
                switch (stoi(paramnum))
                {
                case 1:
                    cout << "New name > ";
                    getline(cin, newpipename);
                    pipestoedit[0][stoi(pipenum)-1] = newpipename;
                    break;
                case 2:
                    

                    int lencheck;

                    while(true){
                    lencheck = 0;
                    cout << "New length > ";
                    getline(cin, newpipelen);;

                    for (int x = 0; x < newpipelen.length(); x ++){
                            if (isdigit(newpipelen[x]) == false){
                                lencheck += 1;
                                break;
                            }
                        }
                    if (lencheck == 0){
                        break;
                    }
                    }
                    pipestoedit[1][stoi(pipenum)-1] =newpipelen;
                    break;
                case 3:
                    int dimcheck;
                    while(true){
                    dimcheck = 0;
                    cout << "New diameter > ";
                    getline(cin, newpipedim);

                    for (int x = 0; x < newpipedim.length(); x ++){
                            if (isdigit(newpipedim[x]) == false){
                                dimcheck += 1;
                                break;
                            }
                        }
                    if (dimcheck == 0){
                        break;
                    }
                    }
                    pipestoedit[2][stoi(pipenum)-1] = newpipedim;
                    break;
                case 4:

                    while(true){
                        cout << "New repair status [y/n] > ";
                        getline(cin, newpipestat);

                        if (newpipestat == "y" ||newpipestat == "Y"){
                            newpipestat = "y";
                            break;
                        } else if (newpipestat == "n" || newpipestat == "N"){
                            newpipestat = "n";
                            break;
                            }  
                        }
                    pipestoedit[3][stoi(pipenum)-1] = newpipestat;
                    break;
                }

                break;
            }
        }
    }
    
    return pipestoedit;
}

auto edit_css(vector<vector<string>> csstoedit){

    
    string newcsname,newcswork,newcsworkon, newcseff,
    csnum, paramnum;
    int editcheck;
    bool editswitch = false;

    //cout << pipestoedit[0].size() << endl;
    while (true)
    {
        editcheck = 0;
        cout << "Station number > ";
        getline(cin, csnum);

        for (int x = 0; x < csnum.length(); x ++){
            if (isdigit(csnum[x]) == false){
                editcheck += 1;
                break;
            }
        }
        //cout << "editcheck" << editcheck << endl;

        if (editcheck == 0){
            //cout << "test1 + " << endl;
            //cout << stoi(pipenum) << endl;
            if (stoi(csnum) >= 1 && stoi(csnum) <= csstoedit[4].size()){
                editswitch = true;
                break;
            }
    
        }
        //cout << editswitch << endl;
    }

    cout << csstoedit[4][stoi(csnum)-1] << ", " << csstoedit[5][stoi(csnum)-1] << ", "
    << csstoedit[6][stoi(csnum)-1] << ", " << csstoedit[7][stoi(csnum)-1] << ";" << endl;

    while (true)
    {
        cout << "1 - Name\n2 - Workshops\n3 - Wrokshops in work\n4 - Efficiency" << endl;
        editcheck = 0;
        cout << "Parameter number > ";
        getline(cin, paramnum);

        for (int x = 0; x < paramnum.length(); x ++){
            if (isdigit(paramnum[x]) == false){
                editcheck += 1;
                break;
            }
        }

        if (editcheck == 0){
            if (stoi(paramnum) >= 1 && stoi(paramnum) <= 4){
                switch (stoi(paramnum))
                {
                case 1:
                    cout << "New station name > ";
                    getline(cin, newcsname);
                    csstoedit[4][stoi(csnum)-1] = newcsname;
                    break;
                case 2:
                    

                    int lencheck;

                    while(true){
                    lencheck = 0;
                    cout << "New number of workshops > ";
                    getline(cin, newcswork);;

                    for (int x = 0; x < newcswork.length(); x ++){
                            if (isdigit(newcswork[x]) == false){
                                lencheck += 1;
                                break;
                            }
                        }
                    if (lencheck == 0){
                        break;
                    }
                    }
                    csstoedit[5][stoi(csnum)-1] =newcswork;
                    break;
                case 3:
                    int dimcheck;
                    while(true){
                    dimcheck = 0;
                    cout << "New number of workshops in work > ";
                    getline(cin, newcsworkon);

                    for (int x = 0; x < newcsworkon.length(); x ++){
                            if (isdigit(newcsworkon[x]) == false){
                                dimcheck += 1;
                                break;
                            }
                        }
                    if (dimcheck == 0){
                        break;
                    }
                    }
                    csstoedit[6][stoi(csnum)-1] = newcsworkon;
                    break;
                case 4:

                    int effcheck;
                    while(true){
                    effcheck = 0;
                    cout << "New efficiency > ";
                    getline(cin, newcseff);

                    for (int x = 0; x < newcseff.length(); x ++){
                            if (isdigit(newcseff[x]) == false){
                                effcheck += 1;
                                break;
                            }
                        }
                    if (effcheck == 0){
                        break;
                    }
                    }
                    csstoedit[7][stoi(csnum)-1] = newcseff;
                    
                    break;
                }

                break;
            }
        }
    }
    
    return csstoedit;

}

inline bool exists_test1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void save_edits(int pipescount, int csscount,vector<vector<string>> primeinfotosave){

    fstream config;
    string config_name;

    bool rewritestatus = false;
    bool exist = false;
    bool deletefile = false;

    cout << "\nFile name > ";
    getline(cin, config_name);

    cout << exists_test1(config_name) << endl;
    config.open(config_name + ".csv", ios::out);

    if(config){  
        exist = true;
    }

    if (exist == true){
        string rewrite;
        while (true)
        {
            cout << "You sure you want to save " + config_name +".csv [Y/N] > ";
            getline(cin, rewrite);

            if (rewrite == "Y" || rewrite == "y"){
                rewritestatus = true;
                break;
            } else if (rewrite == "N" || rewrite == "n"){
                deletefile = true;
                break;
            }
        }
    }
    //cout << "Pipes:" << endl;
    if (exist == false || rewritestatus == true) {
        for (int i = 0; i < pipescount; i++){
        //cout<< i+1 << ") "<< primeinfotosave[0][i] << ", " << primeinfotosave[1][i] << endl;
        config << ", p," << primeinfotosave[0][i] << "," << primeinfotosave[1][i] <<
        "," <<  primeinfotosave[2][i] << "," << primeinfotosave[3][i] << endl;
        }

        for (int i = 0; i < csscount; i++){
            config << ", c," << primeinfotosave[4][i] << "," << primeinfotosave[5][i] <<
            "," <<  primeinfotosave[6][i] << "," << primeinfotosave[7][i] << endl;
        }
    }
   
    config.close();
    
}

auto load_file(){
    string loadname, tempstr, line;
    ifstream loadfile;
    vector<vector<string>> loadinfo = {
    {}, {}, {},
    {}, {}, {},
    {}, {}
    };

    int wordcount;

    cout << "File name > ";
    getline(cin, loadname);

    loadfile.open(loadname + ".csv");

    if (loadfile){
        //cout << "+" << endl;

        while (loadfile >> tempstr){

            string ptempname, ptemplen, ptempdim, ptempstat,
            ctempname, ctempwork, ctempworkon, ctempeff;

            getline(loadfile, line);
            wordcount = 0;

            //cout << typeid(line).name() << endl;
            //cout << line[1] << endl;
            if (string(1, line[1]) == "p"){
                for (int i = 3; i < line.length(); i++){
                    if(string(1, line[i]) != "," && wordcount == 0){
                        ptempname += string(1, line[i]);
                    } else if (string(1, line[i]) == ","){
                        wordcount += 1;
                    } else if(string(1, line[i]) != "," && wordcount == 1){
                        ptemplen += string(1, line[i]);
                    } else if(string(1, line[i]) != "," && wordcount == 2){
                        ptempdim += string(1, line[i]);
                    } else if(string(1, line[i]) != "," && wordcount == 3){
                        ptempstat += string(1, line[i]);
                    }
                }
                loadinfo[0].push_back(ptempname);
                loadinfo[1].push_back(ptemplen);
                loadinfo[2].push_back(ptempdim);
                loadinfo[3].push_back(ptempstat);
            } else if (string(1, line[1]) == "c"){
                for (int i = 3; i < line.length(); i++){
                    if(string(1, line[i]) != "," && wordcount == 0){
                        ctempname += string(1, line[i]);
                    } else if (string(1, line[i]) == ","){
                        wordcount += 1;
                    } else if(string(1, line[i]) != "," && wordcount == 1){
                        ctempwork += string(1, line[i]);
                    } else if(string(1, line[i]) != "," && wordcount == 2){
                        ctempworkon += string(1, line[i]);
                    } else if(string(1, line[i]) != "," && wordcount == 3){
                        ctempeff += string(1, line[i]);
                    }
                }
                loadinfo[4].push_back(ctempname);
                loadinfo[5].push_back(ctempwork);
                loadinfo[6].push_back(ctempworkon);
                loadinfo[7].push_back(ctempeff);
            }

            //cout << ptempname << " " << ptemplen << endl;
        }
        loadfile.close();
    } else {
        cout << "File with such name was not found" << endl;
    }
    //cout << "loaded" << endl;
    return loadinfo;
}

int main_menu(){


    string menuvall;
    int menucheck;
    
    while(true){
        
        menucheck = 0;

        cout << "\n1. Add pipe" << endl;
        cout << "2. Add compressor station" << endl;
        cout << "3. View object list" << endl;
        cout << "4. Edit pipe" << endl;
        cout << "5. Edit compressor station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;
        cout << "-> ";

        getline(cin, menuvall);

        //cout << "enter get" << endl;

        for (int x = 0; x < menuvall.length(); x ++){
            if (isdigit(menuvall[x]) == false){
                menucheck += 1;
                break;
            }
        } 
        //cout << "input scanned" << endl;
        //cout << menucheck << endl;
        if (menucheck == 0){
            if (stoi(menuvall) <= 7 && stoi(menuvall) >= 0){
                break;
            }
        }
        //cout << "iput checked" << endl;
    }
            
    return stoi(menuvall);

}

int main(int argc, char** argv){

    vector <string> temppipe, tempcs;
    vector<vector<string>> primeinfo = {
    {}, {}, {},
    {}, {}, {},
    {}, {}
    };

    string savingyorn, exitstr;

    int menunum;
    bool programon = true;
    bool savestatus = true;
    bool savingwithout;

    while(programon == true){

    menunum = main_menu();

    //cout << "Menunum = " << menunum << endl;

    switch(menunum){
        case 1:
            //cout << "funtion 1" << endl;

            temppipe = add_pipe();
            /*
            cout << temppipe[0] << endl;
            cout << temppipe[1] << endl;
            cout << temppipe[2] << endl;
            */

            //cout << "New pipe:\n" << temppipe[0] << ", " << temppipe[1] << ", " << temppipe[2] << endl;
            primeinfo[0].push_back(temppipe[0]);
            primeinfo[1].push_back(temppipe[1]);
            primeinfo[2].push_back(temppipe[2]);
            primeinfo[3].push_back(temppipe[3]);
            cout << "New pipe was successfully added\n" << endl;
            savestatus = false;

            break;
        case 2:
            //cout << "funtion 2" << endl;
            tempcs = add_css();

            primeinfo[4].push_back(tempcs[0]);
            primeinfo[5].push_back(tempcs[1]);
            primeinfo[6].push_back(tempcs[2]);
            primeinfo[7].push_back(tempcs[3]);
            cout << "New compressor station was successfully added\n" << endl;
            savestatus = false;

            break;
        case 3:
            //cout << "funtion 3" << endl;
            print_list(primeinfo);
            
            break;
        case 4:
            //cout << "funtion 4" << endl;

            primeinfo = edit_pipe(primeinfo);
            savestatus = false;
            cout << "Pipe was successfully edited\n" << endl;
            break;
        case 5:
            //cout << "funtion 5" << endl;

            primeinfo = edit_css(primeinfo);
            savestatus = false;
            cout << "Compressor station was successfully edited\n" << endl;
            break;
        case 6:
            //cout << "funtion 6" << endl;
            save_edits(primeinfo[0].size(),primeinfo[4].size(),primeinfo);

            savestatus = true;
            cout << "Saving is complete\n" << endl;
            break;
        case 7:
            //cout << "funtion 7" << endl;
            savingwithout = false;
            if (!savestatus) {     
                
                while (true)
                {
                    cout << "You sure you want to load without saving? [Y/N] > ";
                    getline(cin, savingyorn);
                    if (savingyorn == "Y" || savingyorn == "y"){
                        savingwithout = true;
                        break;
                    } else if(savingyorn == "N" || savingyorn == "n"){
                        break;
                    }
                }
                
                
            }
            if (savestatus == true || savingwithout == true){
            for (int i = 0; i < primeinfo.size(); i++){
                    primeinfo[i].clear();
                }

            primeinfo = load_file();
            }
            //cout << primeinfo.size() << endl;
            //cout << temploadinfo[0].size() << endl;
            /*
            for (int i = 0; i < primeinfo.size(); i++){
                for (int j = 0; j < primeinfo[i].size(); j++){
                    cout << primeinfo[i][j];
                }
                cout << "\n";
            }
            */
            cout << "Loading is complete\n" << endl;
            break;
        case 0:
            //cout << "funtion 0" << endl;

            if (!savestatus) {
                while (true)
                {
                    cout << "You sure you want to exit without saving? [Y/N] > ";
                    getline(cin, exitstr);

                    if (exitstr == "Y" || exitstr == "y"){
                        savestatus = true;
                        break;
                    } else if(exitstr == "N" || exitstr == "n"){
                        break;
                    }

                }
                
            }
            if (savestatus){
                programon = false;
            }

            break;
    }
    }
}