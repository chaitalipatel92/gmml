// Author: Alireza Khatamian

#include "../../../includes/FileSet/PdbFileSpace/pdbheterogenname.hpp"
#include "../../../includes/utils.hpp"

using namespace std;
using namespace PdbFileSpace;
using namespace gmml;

//////////////////////////////////////////////////////////
//                       CONSTRUCTOR                    //
//////////////////////////////////////////////////////////
PdbHeterogenName::PdbHeterogenName() : heterogen_identifier_(""), heterogen_name_("") {}
PdbHeterogenName::PdbHeterogenName(const string &heterogen_identifier, const string &heterogen_name) :
    heterogen_identifier_(heterogen_identifier), heterogen_name_(heterogen_name) {}

PdbHeterogenName::PdbHeterogenName(stringstream& stream_block)
{
    string line;
    bool is_heterogen_identifier_set = false;
    stringstream ss;
    getline(stream_block, line);
    line = Trim(line);
    while (!Trim(line).empty())
    {
        if(!is_heterogen_identifier_set){
            heterogen_identifier_ = line.substr(11,3);
            is_heterogen_identifier_set = true;
        }

        ss << line.substr(15,55) << " ";

        getline(stream_block, line);
    }
    heterogen_name_ = ss.str();
}

//////////////////////////////////////////////////////////
//                         ACCESSOR                     //
//////////////////////////////////////////////////////////
string PdbHeterogenName::GetHeterogenIdentifier()
{
    return heterogen_identifier_;
}

string PdbHeterogenName::GetHeterogenName()
{
    return heterogen_name_;
}

//////////////////////////////////////////////////////////
//                          MUTATOR                     //
//////////////////////////////////////////////////////////
void PdbHeterogenName::SetHeterogenIdentifier(const string heterogen_identifier)
{
    heterogen_identifier_ = heterogen_identifier;
}

void PdbHeterogenName::SetHeterogenName(const string heterogen_name)
{
    heterogen_name_ = heterogen_name;
}

//////////////////////////////////////////////////////////
//                        FUNCTIONS                     //
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//                      DISPLAY FUNCTION                //
//////////////////////////////////////////////////////////

