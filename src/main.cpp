#include "userReporter.hpp"

int main()
{
    int loops = 9999999;
    UserReport userReport = UserReport();
    userReport.reportUser("user_1");
    userReport.reportUser("user_2");
    userReport.printRatio(loops);
    userReport.reportUser("user_1");
    userReport.printRatio(loops);
    userReport.unreportUser("user_1");
    userReport.printRatio(loops);
    userReport.reportUser("user_3");
    userReport.printRatio(loops);
    return 0;
}