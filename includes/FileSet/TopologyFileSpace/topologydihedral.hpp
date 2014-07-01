#ifndef TOPOLOGYDIHEDRAL_HPP
#define TOPOLOGYDIHEDRAL_HPP

#include <string>
#include <iostream>
#include <vector>

namespace TopologyFileSpace
{
    class TopologyDihedral
    {
        public:
            //////////////////////////////////////////////////////////
            //                       CONSTRUCTOR                    //
            //////////////////////////////////////////////////////////
            /*! \fn
              * Default constructor
              */
            TopologyDihedral();

            TopologyDihedral(std::vector<std::string> dihedral_atoms);

            //////////////////////////////////////////////////////////
            //                       ACCESSOR                       //
            //////////////////////////////////////////////////////////
            /*! \fn
              * An accessor function in order to access to the dihedrals
              * @return dihedrals_ attribute of the current object of this class
              */
            std::vector<std::string> GetDihedrals();
            /*! \fn
              * An accessor function in order to access to boolean value that indicates if dihedral is improper
              * @return is_improper_ attribute of the current object of this class
              */
            bool GetIsImproper();
            /*! \fn
              * An accessor function in order to access to boolean value that indicates if dihedral is in ignored group interaction
              * @return ignored_group_interaction_ attribute of the current object of this class
              */
            bool GetIgnoredGroupInteraction();
            bool GetIncludingHydrogen();

            //////////////////////////////////////////////////////////
            //                       MUTATOR                        //
            //////////////////////////////////////////////////////////
            /*! \fn
              * A mutator function in order to set the dihedrals of the current object
              * Set the dihedrals_ attribute of the current topology dihedral
              * @param dihedrals The dihedrals attribute of the current object
              */
            void SetDihedrals(std::vector<std::string> dihedrals);
            /*! \fn
              * A mutator function in order to set the boolean improper attribute of the current object
              * Set the is_improper_ attribute of the current topology dihedral type
              * @param is_improper The is improper attribute of the current object
              */
            void SetIsImproper(bool is_improper);
            /*! \fn
              * A mutator function in order to set the boolean ignored group interaction of the current object
              * Set the ignored_group_interaction_ attribute of the current topology dihedral type
              * @param ignored_group_interaction The ignored group interactionr attribute of the current object
              */
            void SetIgnoredGroupInteraction(bool ignored_group_interaction);
            void SetIncludingHydrogen(bool including_hydrogen);

            //////////////////////////////////////////////////////////
            //                        FUNCTIONS                     //
            //////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////
            //                       DISPLAY FUNCTION               //
            //////////////////////////////////////////////////////////
            /*! \fn
              * A function to print out the topology dihedral contents in a structural format
              * Print out the information in a defined structure
              * @param out An output stream, the print result will be written in the given output stream
              */
            void Print(std::ostream& out = std::cout);

        private:
            //////////////////////////////////////////////////////////
            //                       ATTRIBUTES                     //
            //////////////////////////////////////////////////////////
            std::vector<std::string> dihedrals_;
            bool is_improper_;
            bool ignored_group_interaction_;
            bool including_hydrogen_;

    };
}

#endif // TOPOLOGYDIHEDRAL_HPP
