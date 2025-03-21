
#include <string>
using namespace std;

namespace CRM{
    class Customer{
        public:
            int id;
            char fullName[100];
            char contactNumber[10];
            char email[200];
            int age;
    };

    class Profile{
        public :
            string shippingAddress;
            string billingAddress;
            string username;
            int rewardPoints;
            string preferredPaymentMethod;
    };
}