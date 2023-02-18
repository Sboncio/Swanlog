#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

class swanlog {
    private:
        const std::string root_file = "./logs/";
        std::string current_log_file;

        void makeFolder(std::string folder_location){
            std::string folderPath = folder_location;
            const char* path = folderPath.c_str();

            std::cout << path << std::endl;

            if (mkdir(path, 0777) == -1)
                std::cerr << "Error :  " << strerror(errno) << std::endl;
 
            

        }


        void makeFile(){
            std::string filePath = root_file + '/' + current_log_file + '/' + current_log_file+".txt";
            const char* path = filePath.c_str();

            std::ofstream file(path);
                if(file.is_open()){
                    file << "LOGGING INITIALISED\n";
                    file.close();
                }
            }

        

        bool checkIfFileExists(){
            std::string pathToLogFile = root_file + current_log_file + '/' + current_log_file + ".txt";

            std::cout << pathToLogFile << std::endl;
            
            const char* path = pathToLogFile.c_str();

            struct stat buffer;
            if (stat(path, &buffer)== 0){
                if(S_ISREG(buffer.st_mode)){
                    //std::cout << "File Exists" << std::endl;
                    return true;
                } 
            } else {
               // std::cout << "File or folder doesn't exist" << std::endl;
                return false;
            }
            return true;
        }
        //bool checkIfFolderExists();



    public:


        swanlog(std::string filename){
            current_log_file = filename;
            if(!checkIfFileExists()){
                makeFolder(root_file);
                makeFolder(root_file + '/' +current_log_file);
                makeFile();
            } else {
                writeline("\n==========\nLOGGING INITIALISED\n==========\n");
            }
        }


        ~swanlog(){

        }

        void writeline(std::string logdata, int level = 1){
            std::string filePath = root_file + '/' + current_log_file + '/' + current_log_file+".txt";
            const char* path = filePath.c_str();

            time_t now = time(0);
   
            // convert now to string form
            char* dt = ctime(&now);

            std::string logLevel;

            //Define logging level
            switch(level){
                case 1:
                    logLevel = "\tLOG:\t";
                    break;
                case 2:
                    logLevel = "\tWARNING:\t";
                    break;
                case 3:
                    logLevel = "\tERROR:\t";
                    break;
            }

            std::string dataToBeLogged = dt + logLevel + logdata + "\n";

            const char* data = dataToBeLogged.c_str();

            std::ofstream file;
            file.open(path, std::ios_base::app);
            if (file.is_open())
                file.write(dataToBeLogged.data(), dataToBeLogged.size());
            
        }
};


