import Curriculum_Vitae

class Personal_Data:
    firstname = 'Rafał'
    lastname = 'Kowalewski'
    birth_date = date(1991,4,27)
    phone_number = 601 460 778
    email = 'kontakt@rafalkowalewski.pl'
    linkedIn = 'linkedin.com/in/oniongeek'
    Education = {
        '02/2019'     : 'Graduation engineering exam',
        '2011 - 2015' : 'Engineer IT Specialist, Nicolaus Copernicus University in Toruń',
        '2007 - 2011' : 'Technician IT Specialist, Electrician School Complex in Włocławek'
    }


class Experience:
    def Junior_Dev(begin_date=date(2019,6,1)):
        company = 'Indorama Ventures Poland'
        duty = { 'creating web tools for office workers',
                 'creating mobile application to manage warehouse',
                 'improving company ERP system' }
        used_technology = { 'C#', 'Java' }
    def Freelancer(begin_date=date(2018,9,1)):
        duty = { 'be a part of startup team',
                 'creating backend Rest API',
                 'regular IT services' }
        used_technology = { 'python', 'Flask' }
    def Electronic_Technician(begin_date=date(2016,4,1)):
        company = 'Jabil Circuit Poland in Kwidzyn'
        duty = { 'test line monitoring and improvement',
                 'test fixtures maintenance' }
        used_technology = { 'HP/UX', 'VB', 'NI TestStand'}


class Skills:
    programing_language_used_in_practics = {
        { 'python' : ('Django','Flask','SQLAlchemy') },
        { 'C#',    : ('ASP.NET Web Application',)},
        { 'Java'   : ('Android application',) }  }
    programing_language_used_in_school_or_accidentally =
        { 'C', 'C++', 'C for AVR', 'VB' ,'C for STM32', 'Arduino' }
    database_language = {'Oracle SQL', 'MySQL'}
    administrative_skills = {'manage Linux/Ubuntu,Debian server'}
    project_manage_tools = {'GIT', 'Trello', 'Bitbucket'}
    driving_licence = {'category B'}
    language = 'english - B1'


class My_Projects:
    project[0] = 'startup project - "Tag&Frag"'
    project[1] = 'engineering work - "Smart Cooling Pad"'
    project[2] = 'startup project - "Phemo"'

    def Want_to_know_more_details():
        Call(Personal_Data.phone_number)
