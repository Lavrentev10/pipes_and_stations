#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct pipe_structure{
    string name;
    int length;
    int diameter;
    string repair_status;
};

vector <pipe_structure> pipe_vecor;

struct cs_structure{
    string name;
    int workshops;
    int workshops_in_work;
    int efficiency;
};

vector <cs_structure> cs_vecor;

bool int_input_check(string inserted_num){
    bool inserted_bumber_flag{0};

    if (inserted_num.length() > 0 ){
        inserted_bumber_flag = 1;
        for (int x = 0; x < inserted_num.length(); x ++){
                if (isdigit(inserted_num[x]) == false){
                    inserted_bumber_flag = 0;
                    break;
                }
            }
        if (inserted_bumber_flag == 1){
            if (stoi(inserted_num) <= 0){
                inserted_bumber_flag = 0;  
            }
        }
    }
    return inserted_bumber_flag;
}

int yes_no_input_check(string user_input){
    int user_input_flag;

    if (user_input == "y" || user_input == "n" || user_input == "Y" || user_input == "N"){
        if (user_input == "y" ||user_input == "Y"){
                user_input_flag = 1;
            } else if (user_input == "n" || user_input == "N"){
                user_input_flag = 0;
            }
    } else {
        user_input_flag = 2;
    }
    return user_input_flag;
}


void add_pipe_function(){

    bool correct_input{0};
    int bool_input_check;
    string new_pipe_name, new_pipe_dim, new_pipe_len, new_pipe_stat,temp_pipe_stat_to_lower;

    while (true)
    {
        cout << "Pipe name > ";
        getline(cin, new_pipe_name);

        if (new_pipe_name.length() > 0){
            break;
        }
    }

    while(true){
        cout << "Pipe length > ";
        getline(cin, new_pipe_len);

        if(int_input_check(new_pipe_len) == 1){
            if (stoi(new_pipe_len) > 0){
                break;
            } else {
                cout << "Invalid value" << endl;
            }
        } else{
            cout << "Warning! Length should be an intager" << endl;
        }
    }

    while(true){
        cout << "Pipe dimameter > ";
        getline(cin, new_pipe_dim);

        if (int_input_check(new_pipe_dim) == 1){
            if (stoi(new_pipe_dim) > 0) {
                break;
            } else{
                cout << "Invalid value" << endl;
            }
        }
            cout << "Warning! Diameter should be an intager" << endl;

    }

    while(true){
        cout << "Repair status [Y/N] > ";
        getline(cin, new_pipe_stat);

        bool_input_check = yes_no_input_check(new_pipe_stat);

        if (bool_input_check == 2){
            cout << "Warning! Invalid value" << endl;
        } else{
            temp_pipe_stat_to_lower = new_pipe_stat;

            transform(temp_pipe_stat_to_lower.begin(),
                temp_pipe_stat_to_lower.end(), temp_pipe_stat_to_lower.begin(),
                [](unsigned char c_pipe_stat)
                {return tolower(c_pipe_stat);});

            correct_input = bool_input_check;
            break;
        }
    }

    pipe_vecor.push_back(pipe_structure{new_pipe_name,stoi(new_pipe_len), stoi(new_pipe_dim), temp_pipe_stat_to_lower});

    cout << "\nNew pipe #" << pipe_vecor.size()<< "\nName: " 
    << pipe_vecor[pipe_vecor.size()-1].name <<"\nLength: " 
    << pipe_vecor[pipe_vecor.size()-1].length 
    << "\nDiameter: "<<pipe_vecor[pipe_vecor.size()-1].diameter
    << "\nRpair status: " << pipe_vecor[pipe_vecor.size()-1].repair_status
    << "\nhas been added successfully\n" << endl;
    
}

void add_cs_function(){
    bool correct_input{0};
    string new_cs_name, new_cs_workshops, new_cs_workshops_in_work, new_cs_efficiency;

    while (true)
    {
        cout << "Station name > ";
        getline(cin, new_cs_name);

        if (new_cs_name.length() > 0){
            break;
        }
    }

    while(correct_input != 1){
        cout << "Workshops > ";
        getline(cin, new_cs_workshops);

        correct_input = int_input_check(new_cs_workshops);

        if (correct_input == 0){
            cout << "Warning! Number of workshops should be an intager" << endl;
        } 
    }

    while (true)
    {
        cout << "Workshops in work > ";
        getline(cin, new_cs_workshops_in_work);

        correct_input = int_input_check(new_cs_workshops_in_work);

        if (correct_input == 0){
            cout << "Warning! Number of workshops should be an intager" << endl;
        } else if (correct_input == 1){
            if (stoi(new_cs_workshops_in_work) > stoi(new_cs_workshops)){
                cout << "Warning! Number of workshops in work cannot exceed the total number of workshops" 
                << endl;
            } else{
                break;
            }
        }
    }
    while(true){
        cout << "Efficiency in percentage > ";
        getline(cin, new_cs_efficiency);

        correct_input = int_input_check(new_cs_efficiency);

        if (correct_input == 0){
            cout << "Warning! Efficiency should be an intager" << endl;
        } else if (correct_input == 1){
            if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100){
                break;
            } else{
                cout << "Percentage value must be between 0 and 100" << endl;
            }
        }
    }

    cs_vecor.push_back(cs_structure{new_cs_name,stoi(new_cs_workshops),
    stoi(new_cs_workshops_in_work), stoi(new_cs_efficiency)});

    cout << "\nNew station #" << cs_vecor.size()<<"\nName: " 
    << cs_vecor[cs_vecor.size()-1].name << "\nWorkshops: "<< cs_vecor[cs_vecor.size()-1].workshops
    << "\nWorkshops in work: " << cs_vecor[cs_vecor.size()-1].workshops_in_work <<
    "\nEfficiency: " << cs_vecor[cs_vecor.size()-1].efficiency<< "\nhas been added successfully\n"
    << endl;

}

void print_pipe(int id, string name, int len, int dim, string stat){
    cout << "\n\tPipe #" << id + 1<< ":"<< endl;
    cout << "\tName: " << name << endl;
    cout << "\tLength: " << len << endl;
    cout << "\tDiameter: " << dim << endl;
    cout << "\tRepair status: " << stat << endl;
}

void print_cs(int id, string name, int ws, int ws_i, int eff){
    cout << "\n\tCompressor station #" << id << ":"<< endl;
    cout << "\tName: " << name << endl;
    cout << "\tWorkshops: " << ws << endl;
    cout << "\tWorkshops in work: " << ws_i << endl;
    cout << "\tEfficiency: " << eff << endl; 
}

void view_all_entities(){
    bool view_menu_flag = 1;
    string view_menu_choice, search_pipe_by, pipe_search_name, pipe_search_stat, pipe_search_id,
    search_cs_by, cs_search_name, cs_search_id, cs_search_percentage,cs_percentage_low_or_high;

    while (view_menu_flag)
    {
        cout << "\n1 - Search pipe\n2 - Search station\n3 - Display full list\n > ";
        getline(cin, view_menu_choice);
        if(int_input_check(view_menu_choice) == 1){
            if (stoi(view_menu_choice) >=1 && stoi(view_menu_choice) <= 3){
                view_menu_flag = 0;
            } else{
                cout << "Invalid value!" << endl;
            }
        } else{
            cout << "The entered number is not an integer" << endl;
        }
    }

    switch (stoi(view_menu_choice))
    {
    case 1:
        while (true)
        {
            cout << "\n1 - By name\n2 - By index\n3 - By repair status\n > ";
            getline(cin, search_pipe_by);

            if (int_input_check(search_pipe_by) == 1){
                if (stoi(search_pipe_by) == 1 || stoi(search_pipe_by) == 2 || stoi(search_pipe_by) == 3){
                    break;
                } else {
                    cout << "The value must be between 1 and 3" << endl;
                }
            } else{
                cout << "Value must be integer!" << endl;
            }
        }
        switch (stoi(search_pipe_by))
        {
        case 1:
            while(true){
                cout << "Name (press enter to exit)\n > ";
                getline(cin,pipe_search_name);
                if (pipe_search_name.length() == 0){
                    break;
                } else{
                    for (int i = 0; i < pipe_vecor.size(); i++){
                        if (pipe_vecor[i].name == pipe_search_name){

                            print_pipe(i, pipe_vecor[i].name,pipe_vecor[i].length,
                            pipe_vecor[i].diameter, pipe_vecor[i].repair_status);
                        }
                    }
                    break;
                }
            }

            break;
        case 2:
            while (true)
            {
                cout << "Index (press enter to exit)\n" << "Pipes: " << pipe_vecor.size()
                << endl;
                getline(cin, pipe_search_id);
                if (int_input_check(pipe_search_id) == 1){
                    if (stoi(pipe_search_id)-1 >= 0 && stoi(pipe_search_id)-1 < pipe_vecor.size()){

                        print_pipe(stoi(pipe_search_id)-1, pipe_vecor[stoi(pipe_search_id)-1].name,
                        pipe_vecor[stoi(pipe_search_id)-1].length,
                        pipe_vecor[stoi(pipe_search_id)-1].diameter, 
                        pipe_vecor[stoi(pipe_search_id)-1].repair_status);
                    }
                    break;
                }
            }
            
            break;
        case 3:
            while (true)
            {
                cout << "Repair status [Y/N] (press enter to exit)\n" << endl;
                getline(cin, pipe_search_stat);
                string temp_pipe_stat_to_lower = pipe_search_stat;
                string temp_pipe_stat_to_upper = pipe_search_stat;
                transform(temp_pipe_stat_to_lower.begin(),
                    temp_pipe_stat_to_lower.end(), temp_pipe_stat_to_lower.begin(),
                    [](unsigned char c_pipe_stat)
                    {return tolower(c_pipe_stat);});
                transform(temp_pipe_stat_to_upper.begin(),
                    temp_pipe_stat_to_upper.end(), temp_pipe_stat_to_upper.begin(),
                    [](unsigned char c_pipe_stat)
                    {return tolower(c_pipe_stat);});
                for (int i = 0; i < pipe_vecor.size(); i++){
                    if (pipe_vecor[i].repair_status == temp_pipe_stat_to_lower 
                    || pipe_vecor[i].repair_status == temp_pipe_stat_to_upper){
                        print_pipe(i, pipe_vecor[i].name,pipe_vecor[i].length,
                        pipe_vecor[i].diameter, pipe_vecor[i].repair_status);
                    }
                }
                break; 
            }
            break;
        }
        break;
    case 2:
        while (true)
        {
            cout << "\n1 - By name\n2 - By index\n3 - By percentage of unused workshops\n > ";
            getline(cin, search_cs_by);

            if (int_input_check(search_cs_by) == 1){
                if (stoi(search_cs_by) == 1 || stoi(search_cs_by) == 2 || stoi(search_cs_by) == 3){
                    break;
                } else {
                    cout << "The value must be between 1 and 3" << endl;
                }
            } else{
                cout << "Value must be integer!" << endl;
            }
        }
        switch (stoi(search_cs_by))
        {
        case 1:
            while(true){
                cout << "Name (press enter to exit)\n > ";
                getline(cin,cs_search_name);
                if (cs_search_name.length() == 0){
                    break;
                } else{
                    for (int i = 0; i < cs_vecor.size(); i++){
                        if (cs_vecor[i].name == cs_search_name){

                            print_cs(i, cs_vecor[i].name, cs_vecor[i].workshops,
                            cs_vecor[i].workshops_in_work, cs_vecor[i].efficiency);
                        }
                    }
                    break;
                }
            }
            break;
        case 2:
            while (true)
            {
                cout << "Index (press enter to exit)\n" << "Stations: " << cs_vecor.size()
                << endl;
                getline(cin, cs_search_id);
                if (int_input_check(cs_search_id) == 1){
                    if (stoi(cs_search_id)-1 >= 0 && stoi(cs_search_id)-1 < cs_vecor.size()){
                
                        print_cs(stoi(cs_search_id)-1, cs_vecor[stoi(cs_search_id)-1].name,
                        cs_vecor[stoi(cs_search_id)-1].workshops,
                        cs_vecor[stoi(cs_search_id)-1].workshops_in_work,
                        cs_vecor[stoi(cs_search_id)-1].efficiency);
                    }
                    break;
                }
            }
            break;
        case 3:
            while (true)
            {
                cout << "Enter percentage of unused workshops: ";
                getline(cin, cs_search_percentage);
                if(int_input_check(cs_search_percentage) == 1){
                    if (stoi(cs_search_percentage) >= 0 || stoi(cs_search_percentage) <= 100){
                        break;
                    } else {
                        cout << "Out of range (0-100)" << endl;
                    }
                } else {
                    cout << "Not an integer" << endl;
                }
            }

            while (true)
            {
                cout << "1 - Lower than " << cs_search_percentage << "%\n2 - Higher than "
                 << cs_search_percentage << "%\n > ";
                getline(cin, cs_percentage_low_or_high);
                if (int_input_check(cs_percentage_low_or_high) == 1){
                    if (stoi(cs_percentage_low_or_high) == 1){
                        for (int i = 0; i < cs_vecor.size(); i++){
                            if ((cs_vecor[i].workshops - cs_vecor[i].workshops_in_work)/cs_vecor[i].workshops 
                            < stoi(cs_percentage_low_or_high)){
                                cout << cs_vecor[i].name << endl;
                                cout << cs_vecor[i].workshops << endl;
                                cout << cs_vecor[i].workshops_in_work << endl;
                                cout << cs_vecor[i].efficiency << endl;
                                cout << "\n" << endl;

                                print_cs(i, cs_vecor[i].name, cs_vecor[i].workshops,
                                cs_vecor[i].workshops_in_work, cs_vecor[i].efficiency);
                            }
                        }
                        break;
                    } else if (stoi(cs_percentage_low_or_high) == 2){
                        for (int i = 0; i < cs_vecor.size(); i++){
                            if ((cs_vecor[i].workshops - cs_vecor[i].workshops_in_work)/cs_vecor[i].workshops 
                            > stoi(cs_percentage_low_or_high)){
                                cout << cs_vecor[i].name << endl;
                                cout << cs_vecor[i].workshops << endl;
                                cout << cs_vecor[i].workshops_in_work << endl;
                                cout << cs_vecor[i].efficiency << endl;
                                cout << "\n" << endl;

                                print_cs(i, cs_vecor[i].name, cs_vecor[i].workshops, cs_vecor[i].workshops_in_work,
                                cs_vecor[i].efficiency);
                            }
                        }
                        break;
                    } else {
                        cout << "Out of range!" << endl;
                    }
                }
            }          
            
            break;
        }
        break;
    case 3:
        cout << "\nPipes:\n" << endl;
        for (int i = 0; i < pipe_vecor.size(); i++){

            print_pipe(i, pipe_vecor[i].name, pipe_vecor[i].length, pipe_vecor[i].diameter, pipe_vecor[i].repair_status);
        }
        cout << "\nCompressor stations:\n" << endl;
        for (int i = 0; i < cs_vecor.size(); i++){

            print_cs(i, cs_vecor[i].name, cs_vecor[i].workshops, cs_vecor[i].workshops_in_work,cs_vecor[i].efficiency);
        }
        break;
    }
    
}

void edit_pipes(){
    string pipe_id_to_edit, pipe_parameter_to_edit, new_pipe_name, new_pipe_lenght, new_pipe_diameter,
    new_pipe_repair_stat,temp_pipe_stat_to_lower;

    while (true)
    {
        cout << "Id of pipe ("<< pipe_vecor.size()<<" pipes in stock)\n(press enter to exit) > ";
        getline(cin, pipe_id_to_edit);
        if (pipe_id_to_edit.length() == 0){
            break;
        }
        if (int_input_check(pipe_id_to_edit) == 1){
            if (stoi(pipe_id_to_edit)-1 >= 0 && stoi(pipe_id_to_edit)-1 < pipe_vecor.size()){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else {
            cout << "Integer expected" << endl;
        }
    }
    if (pipe_id_to_edit.length() != 0){

        print_pipe(stoi(pipe_id_to_edit)-1, pipe_vecor[stoi(pipe_id_to_edit)-1].name, pipe_vecor[stoi(pipe_id_to_edit)-1].length,
        pipe_vecor[stoi(pipe_id_to_edit)-1].diameter, pipe_vecor[stoi(pipe_id_to_edit)-1].repair_status);

    } else {
        return;   
    }

    while (true)
    {
        cout << "\nSelect parameter of pipe:\n1 - Name\n2 - Length\n3 - Diameter\n4 - Repair status\n > ";
        getline(cin, pipe_parameter_to_edit);

        if (int_input_check(pipe_parameter_to_edit) == 1){
            if (stoi(pipe_parameter_to_edit) >= 1 && stoi(pipe_parameter_to_edit) <= 4){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else {
            cout << "Integer expected" << endl;
        }
    }

    switch (stoi(pipe_parameter_to_edit))
    {
    case 1:
        while (true)
        {
            cout << "New pipe name > ";
            getline(cin, new_pipe_name);

            if (new_pipe_name.length() > 0){
                pipe_vecor[stoi(pipe_id_to_edit)-1].name = new_pipe_name;
                break;
            } else {
                cout << "Name cannot be empty" << endl;
            }
        }
        
        break;
    case 2:
        while (true)
        {
            cout << "New pipe length > ";
            getline(cin, new_pipe_lenght);

            if (int_input_check(new_pipe_lenght) == 1){
                if (stoi(new_pipe_lenght) > 0){
                    pipe_vecor[stoi(pipe_id_to_edit)-1].length = stoi(new_pipe_lenght);
                    break;
                } else {
                    cout << "Length should be bigger than 0";
                }
            } else {
                cout << "Integer expected" << endl;
            }
        }
        
        break;
    case 3:
        while (true)
        {
            cout << "New pipe diameter > ";
            getline(cin, new_pipe_diameter);

            if (int_input_check(new_pipe_diameter) == 1){
                if (stoi(new_pipe_diameter) > 0){
                    pipe_vecor[stoi(pipe_id_to_edit)-1].diameter = stoi(new_pipe_diameter);
                    break;
                } else {
                    cout << "Diameter should be bigger than 0";
                }
            } else {
                cout << "Integer expected" << endl;
            }
        }
        break;
    case 4:
        while(true){
        cout << "Repair status [Y/N] > ";
        getline(cin, new_pipe_repair_stat);

        if (yes_no_input_check(new_pipe_repair_stat) == 2){
            cout << "Warning! Invalid value" << endl;
        } else{
            temp_pipe_stat_to_lower = new_pipe_repair_stat;

            transform(temp_pipe_stat_to_lower.begin(),
                temp_pipe_stat_to_lower.end(), temp_pipe_stat_to_lower.begin(),
                [](unsigned char c_pipe_stat)
                {return tolower(c_pipe_stat);});
            pipe_vecor[stoi(pipe_id_to_edit)-1].repair_status = temp_pipe_stat_to_lower;
            break;
        }
        }

        break;
    }

}

void edit_cs(){

    string cs_id_to_edit, cs_parameter_to_edit, new_cs_name, new_cs_workshops,
    new_cs_workshops_in_work, new_cs_efficiency;
    bool correct_input{0};

    while (true)
    {
        cout << "Id of station ("<< pipe_vecor.size()<<" stations in stock)\n(press enter to exit) > ";
        getline(cin, cs_id_to_edit);
        if (cs_id_to_edit.length() == 0){
            break;
        }
        if (int_input_check(cs_id_to_edit) == 1){
            if (stoi(cs_id_to_edit)-1 >= 0 && stoi(cs_id_to_edit)-1 < pipe_vecor.size()){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else {
            cout << "Integer expected" << endl;
        }
    }
    if (cs_id_to_edit.length() != 0){

        print_cs(stoi(cs_id_to_edit)-1, cs_vecor[stoi(cs_id_to_edit)-1].name,
        cs_vecor[stoi(cs_id_to_edit)-1].workshops, cs_vecor[stoi(cs_id_to_edit)-1].workshops_in_work,
        cs_vecor[stoi(cs_id_to_edit)-1].efficiency);

    } else {
        return;   
    }

    while (true)
    {
        cout << "\nSelect parameter of pipe:\n1 - Name\n2 - Workshops\n3 - Wrokshops in work"
        << "\n4 - Efficiency\n > ";
        getline(cin, cs_parameter_to_edit);

        if (int_input_check(cs_parameter_to_edit) == 1){
            if (stoi(cs_parameter_to_edit) >= 1 && stoi(cs_parameter_to_edit) <= 4){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else {
            cout << "Integer expected" << endl;
        }
    }

    switch (stoi(cs_parameter_to_edit))
    {
    case 1:
        while (true)
        {
            cout << "Station name > ";
            getline(cin, new_cs_name);

            if (new_cs_name.length() > 0){
                break;
            }
        }
        cs_vecor[stoi(cs_id_to_edit)-1].name = new_cs_name;
        break;
    case 2:
        
        while(correct_input != 1){
            cout << "Workshops > ";
            getline(cin, new_cs_workshops);

            correct_input = int_input_check(new_cs_workshops);

            if (correct_input == 0){
                cout << "Warning! Number of workshops should be an intager" << endl;
            } 
        }

        cs_vecor[stoi(cs_id_to_edit) - 1].workshops = stoi(new_cs_workshops);
        
        break;
    case 3:
        while (true)
        {
            cout << "Workshops in work > ";
            getline(cin, new_cs_workshops_in_work);

            correct_input = int_input_check(new_cs_workshops_in_work);

            if (correct_input == 0){
                cout << "Warning! Number of workshops should be an intager" << endl;
            } else if (correct_input == 1){
                if (stoi(new_cs_workshops_in_work) > stoi(new_cs_workshops)){
                    cout << "Warning! Number of workshops in work cannot exceed the total number of workshops" 
                    << endl;
                } else{
                    break;
                }
            }
        }

        cs_vecor[stoi(cs_id_to_edit) - 1].workshops_in_work = stoi(new_cs_workshops);
        
        break;
    case 4:
        while(true){
            cout << "Efficiency in percentage > ";
            getline(cin, new_cs_efficiency);

            correct_input = int_input_check(new_cs_efficiency);

            if (correct_input == 0){
                cout << "Warning! Efficiency should be an intager" << endl;
            } else if (correct_input == 1){
                if (stoi(new_cs_efficiency) >= 0 && stoi(new_cs_efficiency)<= 100){
                    break;
                } else{
                    cout << "Percentage value must be between 0 and 100" << endl;
                }
            }
        }

        cs_vecor[stoi(cs_id_to_edit) - 1].efficiency = stoi(new_cs_efficiency);

        break;
    }

}

inline bool exists_test1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void save_file(){

    fstream config;
    string config_name, rewrite_status;
    bool rewrite_status_check{1};

    cout << "\nFile name > ";
    getline(cin, config_name);

    if (exists_test1(config_name+".csv") == 1){
        while (true)
        {
            cout << "Are sure you want to rewrite the file? [Y/N] > ";
            getline(cin, rewrite_status);

            if (yes_no_input_check(rewrite_status) == 1){
                rewrite_status_check = 1;
                break;
            } else if (yes_no_input_check(rewrite_status) == 0){
                rewrite_status_check = 0;
                break;
            } else{
                cout << "Error while entering a variable!" << endl;
            }
        }            
    }

    if (rewrite_status_check == 1){

        config.open(config_name + ".csv", ios::out);

        for (int i = 0; i < pipe_vecor.size(); i++){
        //cout<< i+1 << ") "<< primeinfotosave[0][i] << ", " << primeinfotosave[1][i] << endl;
        config << ", p," << pipe_vecor[i].name << "," << pipe_vecor[i].length <<
        "," <<  pipe_vecor[i].diameter << "," << pipe_vecor[i].repair_status << endl;
        }

        for (int i = 0; i < cs_vecor.size(); i++){
            config << ", c," << cs_vecor[i].name << "," << cs_vecor[i].workshops <<
            "," <<  cs_vecor[i].workshops_in_work << "," << cs_vecor[i].efficiency << endl;
        }

        config.close();
    }

}

bool load_file(){

    string loadname, tempstr, line;
    ifstream loadfile;
    int wordcount;
    bool file_load_suc_status;

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

                pipe_vecor.push_back(pipe_structure{ptempname,stoi(ptemplen),
                stoi(ptempdim), ptempstat});

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

                cs_vecor.push_back(cs_structure{ctempname,stoi(ctempwork),
                stoi(ctempworkon), stoi(ctempeff)});
            }

            //cout << ptempname << " " << ptemplen << endl;
        }
        loadfile.close();

        return 1;
    } else {
        cout << "File with such name was not found" << endl;

        return 0;
    }
}

int menu(){

    bool main_menu_flag{1};
    string user_menu_insert;

    while(main_menu_flag){

        bool menu_number_is_dig{1};

        cout << "\n1. Add pipe" << endl;
        cout << "2. Add compressor station" << endl;
        cout << "3. View object list" << endl;
        cout << "4. Edit pipe" << endl;
        cout << "5. Edit compressor station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;
        cout << "-> ";

        getline(cin, user_menu_insert);
        if (user_menu_insert.length() > 0){
        for (int x = 0; x < user_menu_insert.length(); x ++){
            if (isdigit(user_menu_insert[x]) == false){
                menu_number_is_dig = 0;
                break;
            }
        }

        if (menu_number_is_dig == 1){
            if (stoi(user_menu_insert) <= 7 && stoi(user_menu_insert) >= 0){
                main_menu_flag = 0;
            }
        } else {
            cout << "\nInvalid value!\n" << endl;
        }

        } else {
            cout << "\nInvalid value!\n" << endl;
        }
    }

    return stoi(user_menu_insert);
}

int main(){

    int user_choice_in_main_menu;
    bool program_cycle{1},file_saved_status{1},load_without_save{0},success_load,
    exit_without_saving{0};
    string load_without_saving_string, exit_without_saving_string;

    while(program_cycle){
        user_choice_in_main_menu = menu();

        switch(user_choice_in_main_menu){
            case 0:
                if (file_saved_status == 0){
                    while(true){
                        cout << "Are you sure you want to exit without saving? [Y/N] > ";
                        getline(cin , exit_without_saving_string);
                        if (yes_no_input_check(exit_without_saving_string) == 1){
                            exit_without_saving = 1;
                            break;
                        } else if (yes_no_input_check(exit_without_saving_string) == 0){
                            exit_without_saving = 0;
                            break;
                        } else {
                            cout << "Incorrect value!" << endl;
                        }
                    }
                }
                if (file_saved_status == 1 || exit_without_saving == 1){        
                    program_cycle = 0;
                }
                
                break;
            case 1:
                add_pipe_function();
                file_saved_status = 0;
                break;
            case 2:
                add_cs_function();
                file_saved_status = 0;
                break;
            case 3:
                view_all_entities();

                break;
            case 4:
                edit_pipes();
                file_saved_status = 0;
                break;
            case 6:
                save_file();
                file_saved_status = 1;
                break;
            case 7:
                load_without_save = 0;
                if (file_saved_status == 0){
                    while(true){
                        cout << "Are you sure you want to load file without saving? [Y/N] > ";
                        getline(cin , load_without_saving_string);
                        if (yes_no_input_check(load_without_saving_string) == 1){
                            load_without_save = 1;
                            break;
                        } else if (yes_no_input_check(load_without_saving_string) == 0){
                            load_without_save = 0;
                            break;
                        } else {
                            cout << "Incorrect value!" << endl;
                        }
                    }
                }
                if (file_saved_status == 1 || load_without_save == 1){        
                    success_load = load_file();
                    if (success_load == 1){
                        file_saved_status = 0;
                    }
                }
                
                break;
        }
    }
}