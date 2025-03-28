#include "medicine.h"
namespace WellnessForever {
    class RepositoryManager{
        public:
            static Medicine  theMedicine;
            static void  saveMedicine();
            static void   getMedicine();
    };
}
 