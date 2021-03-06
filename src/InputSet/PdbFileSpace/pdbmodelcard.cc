#include "../../../includes/InputSet/PdbFileSpace/pdbmodel.hpp"
#include "../../../includes/InputSet/PdbFileSpace/pdbmodelcard.hpp"
#include "../../../includes/utils.hpp"
#include "../../../includes/common.hpp"

using namespace std;
using namespace PdbFileSpace;
using namespace gmml;

//////////////////////////////////////////////////////////
//                       CONSTRUCTOR                    //
//////////////////////////////////////////////////////////
PdbModelCard::PdbModelCard() : record_name_("MODEL") {}

PdbModelCard::PdbModelCard(stringstream &stream_block)
{
    string line;
    bool is_record_name_set = false;
    getline(stream_block, line);
    string temp = line;
    while (!Trim(temp).empty())
    {
        if(line.find("MODEL") != string::npos)
        {
            if(!is_record_name_set){
                record_name_ = line.substr(0,6);
                Trim(record_name_);
                is_record_name_set=true;
            }
            stringstream model_block;
            while(line.find("MODEL") != string::npos || line.find("ATOM") != string::npos || line.find("ANISOU") != string::npos
                    || line.find("TER") != string::npos || line.find("HETATM") != string::npos || line.find("ENDMDL") != string::npos)
            {
                model_block << line << endl;
                getline(stream_block,line);
                temp = line;
            }
            PdbModel* pdb_model = new PdbModel(model_block);
            models_[pdb_model->GetModelSerialNumber()] = pdb_model;
        }
        else
        {
            if(!is_record_name_set){
                record_name_ = "MODEL ";
                Trim(record_name_);
                is_record_name_set = true;
            }
            stringstream model_block;
            while(line.find("MODEL") != string::npos || line.find("ATOM") != string::npos || line.find("ANISOU") != string::npos
                    || line.find("TER") != string::npos || line.find("HETATM") != string::npos || line.find("ENDMDL") != string::npos)
            {
                model_block << line << endl;
                getline(stream_block,line);
                temp = line;
            }
//            cout << model_block.str() << endl;
            PdbModel* pdb_model = new PdbModel(model_block);
            models_[pdb_model->GetModelSerialNumber()] = pdb_model;
        }
    }
}

//////////////////////////////////////////////////////////
//                         ACCESSOR                     //
//////////////////////////////////////////////////////////

string PdbModelCard::GetRecordName(){
    return record_name_;
}

PdbModelCard::PdbModelMap PdbModelCard::GetModels(){
    return models_;
}

//////////////////////////////////////////////////////////
//                       MUTATOR                        //
//////////////////////////////////////////////////////////

void PdbModelCard::SetRecordName(const string record_name){
    record_name_ = record_name;
}

void PdbModelCard::SetModels(PdbModelMap models){
    models_ = models;
}

//////////////////////////////////////////////////////////
//                        FUNCTIONS                     //
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//                      DISPLAY FUNCTION                //
//////////////////////////////////////////////////////////
void PdbModelCard::Print(ostream &out)
{
    out << "Record Name: " << record_name_ << endl <<
           "================= Models =================" << endl;
    for(PdbModelCard::PdbModelMap::iterator it = models_.begin(); it != models_.end(); it++)
    {
        out << "Model Serial Number: ";
        if((it)->first != iNotSet)
            out << (it)->first << endl;
        else
            out << " " << endl;
        (it)->second->Print();
        out << endl;
    }
}
