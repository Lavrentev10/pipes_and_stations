#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct {
    int length;
    int diameter;
    string repair_status;
} pipe_structure;

struct {
    string name;
    int workshops;
    int workshops_in_work;
    int efficiency;
} cs_structure;

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
    string  new_pipe_dim, new_pipe_len, new_pipe_stat,temp_pipe_stat_to_lower;

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
    pipe_structure.length = stoi(new_pipe_len);
    pipe_structure.diameter = stoi(new_pipe_dim);
    pipe_structure.repair_status = temp_pipe_stat_to_lower;

    cout << "\nNew pipe" <<"\nLength: " 
    << pipe_structure.length 
    << "\nDiameter: "<<pipe_structure.diameter
    << "\nRpair status: " << pipe_structure.repair_status
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

    cs_structure.name = new_cs_name;
    cs_structure.workshops = stoi(new_cs_workshops);
    cs_structure.workshops_in_work = stoi(new_cs_workshops_in_work);
    cs_structure.efficiency = stoi(new_cs_efficiency);

    cout << "\nNew station #" << "\nName: " 
    << cs_structure.name << "\nWorkshops: "<< cs_structure.workshops
    << "\nWorkshops in work: " << cs_structure.workshops_in_work <<
    "\nEfficiency: " << cs_structure.efficiency<< "\nhas been added successfully\n"
    << endl;

}

void view_all_entities(){
    cout << "\nPipe:\n\tLength: " << pipe_structure.length << "\n\tDiameter: " <<
    pipe_structure.diameter << "\n\tRepair status: " << pipe_structure.repair_status << endl;

    cout << "\nCompressor station:\n\tName: " << cs_structure.name << "\n\tWorkshops: " <<
    cs_structure.workshops << "\n\tWorkshops in work: " << cs_structure.workshops_in_work <<
    "\n\tEfficiency: " << cs_structure.efficiency << endl;
}

void edit_pipes(){
    string pipe_parameter_to_edit, new_pipe_lenght, new_pipe_diameter,
    new_pipe_repair_stat,temp_pipe_stat_to_lower;

    while (true)
    {
        cout << "Select parameter of pipe:\n1 - Length\n2 - Diameter\n3 - Repair status\n > ";
        getline(cin, pipe_parameter_to_edit);

        if (int_input_check(pipe_parameter_to_edit) == 1){
            if (stoi(pipe_parameter_to_edit) >= 1 && stoi(pipe_parameter_to_edit) <= 3){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else if(pipe_parameter_to_edit.length() == 0){
            return;
        }else {
            cout << "Integer expected" << endl;
        }
    }

    switch (stoi(pipe_parameter_to_edit))
    {
    case 1:
        while (true)
        {
            cout << "New pipe length > ";
            getline(cin, new_pipe_lenght);

            if (int_input_check(new_pipe_lenght) == 1){
                if (stoi(new_pipe_lenght) > 0){
                    pipe_structure.length = stoi(new_pipe_lenght);
                    break;
                } else {
                    cout << "Length should be bigger than 0";
                }
            } else {
                cout << "Integer expected" << endl;
            }
        }
        
        break;
    case 2:
        while (true)
        {
            cout << "New pipe diameter > ";
            getline(cin, new_pipe_diameter);

            if (int_input_check(new_pipe_diameter) == 1){
                if (stoi(new_pipe_diameter) > 0){
                   pipe_structure.diameter = stoi(new_pipe_diameter);
                    break;
                } else {
                    cout << "Diameter should be bigger than 0";
                }
            } else {
                cout << "Integer expected" << endl;
            }
        }
        break;
    case 3:
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
            pipe_structure.repair_status = temp_pipe_stat_to_lower;
            break;
        }
        }

        break;
    }

}

void edit_cs(){

    string cs_parameter_to_edit, new_cs_name, new_cs_workshops, new_cs_workshops_in_work,
    new_cs_efficiency;
    bool correct_input{0};

    while (true)
    {
        cout << "Select parameter of station:\n1 - Name\n2 - Workshops"<<
        "\n3 - Workshops in work\n4 - Efficiency\n > ";
        getline(cin, cs_parameter_to_edit);

        if (int_input_check(cs_parameter_to_edit) == 1){
            if (stoi(cs_parameter_to_edit) >= 1 && stoi(cs_parameter_to_edit) <= 3){
                break;
            } else {
                cout << "Out of range" << endl;
            }
        } else if(cs_parameter_to_edit.length() == 0){
            return;
        }else {
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
        cs_structure.name = new_cs_name;
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
        cs_structure.workshops = stoi(new_cs_workshops);
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
        cs_structure.workshops_in_work = stoi(new_cs_workshops_in_work);
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
        cs_structure.efficiency = stoi(new_cs_efficiency);

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

        //cout<< i+1 << ") "<< primeinfotosave[0][i] << ", " << primeinfotosave[1][i] << endl;
        config << ", p," << pipe_structure.length <<
        "," <<  pipe_structure.diameter << "," << pipe_structure.repair_status << endl;
        
        config << ", c," << cs_structure.name << "," << cs_structure.workshops <<
        "," <<  cs_structure.workshops_in_work << "," << cs_structure.efficiency << endl;

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

            string ptemplen, ptempdim, ptempstat,
            ctempname, ctempwork, ctempworkon, ctempeff;

            getline(loadfile, line);
            wordcount = 0;

            //cout << typeid(line).name() << endl;
            //cout << line[1] << endl;
            if (string(1, line[1]) == "p"){
                for (int i = 3; i < line.length(); i++){
                    if(string(1, line[i]) != "," && wordcount == 0){
                        ptemplen += string(1, line[i]);
                    } else if (string(1, line[i]) == ","){
                        wordcount += 1;
                    } else if(string(1, line[i]) != "," && wordcount == 1){
                        ptempdim += string(1, line[i]);
                    } else if(string(1, line[i]) != "," && wordcount == 2){
                        ptempstat += string(1, line[i]);
                    } 
                }
                pipe_structure.length = stoi(ptemplen);
                pipe_structure.diameter = stoi(ptempdim);
                pipe_structure.repair_status = ptempstat;

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

                cs_structure.name = ctempname;
                cs_structure.workshops = stoi(ctempwork);
                cs_structure.workshops_in_work = stoi(ctempworkon);
                cs_structure.efficiency = stoi(ctempeff);
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
    bool program_cycle{1},file_saved_status{1},exit_without_saving_status,
    load_without_save, success_load;
    string load_without_saving_string, exit_without_saving_status_str;

    while(program_cycle){
        user_choice_in_main_menu = menu();

        switch(user_choice_in_main_menu){
            case 0:
                exit_without_saving_status = 0;
                if (file_saved_status == 0){
                    while (true)
                    {
                        cout << "Are you sure you want to exit without saving? [Y/N] > ";
                        getline(cin , exit_without_saving_status_str);
                        if (yes_no_input_check(exit_without_saving_status_str) == 1){
                            exit_without_saving_status = 1;
                            break;
                        } else if (yes_no_input_check(exit_without_saving_status_str) == 0){
                            exit_without_saving_status = 0;
                            break;
                        } else {
                            cout << "Incorrect value!" << endl;
                        }
                    }
                }
                if (file_saved_status == 1 || exit_without_saving_status == 1){
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
            case 5:
                edit_cs();
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