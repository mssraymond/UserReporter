import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), "build"))

from userReporter import UserReport

if __name__ == "__main__":
    loops = 9999999
    user_report = UserReport()
    user_report.reportUser("user_1")
    user_report.reportUser("user_2")
    user_report.printRatio(loops)
    user_report.reportUser("user_1")
    user_report.printRatio(loops)
    user_report.unreportUser("user_1")
    user_report.printRatio(loops)
    user_report.reportUser("user_3")
    user_report.printRatio(loops)
