 > Remove prompt text (lines beginning with "\>") and replace with your project specifics (including this prompt)
 > Replace anything between \<...\> with your project specifics and remove angle brackets. 
# UCR Course Planner
 > Your author list below should include links to all members GitHub and should begin with a "\>"
 
 > Authors: [Vahagn Tovmasian](https://github.com/Varhagna) [Selma Kondoker](https://github.com/skondoker)
 
 > You will be forming a group of **TWO - THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor, Iterator
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * You can pick any of the following languages:
 >   * C/C++, Java, Python
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [toolname](link) - Short description
 > * What will be the input/output of your project?
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 
 Our project will be a course planning software for UCR students.
 In our experience, showing prospective students the course plan and talking to them about how useful, as well as using it ourselves has shown us the benefits of a good course plan. We want to extend that tool but generate a custom course plan depending on conditions inputted by the user.
 
 This project will be completed in C++, we have yet to decide what tools in specific we will use but will expect to know once we get a better grasp of the exact design details we want to incorporate. We want to be able to generate a PDF or similar output so we may or may not need special libraries for this, however. We also intend to be able to parse through the catalog for a specific inputted major and get the requirements they need & course prereqs and similar requirements.

  * Abstract factory creational pattern to create families of classes from the course catalog.
  * Composite structural pattern to create our class tree and indicate hierarchies with pre-requisites.
  * Observer behavioral pattern to handle and update changes made to the course schedule.

  * We intend to use the [PDFTRON C++ Library](https://www.pdftron.com/documentation/cpp/)
 
 The input output of our project will be any student specific information such as credits completed, courses taken and passed, expected or planned graduation date, which will create a customized course plan they can follow as they progress through their degree.
 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member.
 > * Break down the first "Epic" into smaller user stories (issues) and assign them to the appropriate team member.
## Class Diagram
 > Include a class diagram and a description of the diagram. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. 
   https://docs.google.com/document/d/1O9iIQU9e-WxCcY_7MSfIGi9Epqv_0VS6sOeGDtp6o5U/edit?usp=sharing
   
   Our diagram illustrates a Client which uses the Abstract Factory Pattern to utilise a PDF Parser to read through and construct different Components which can then be constructed into a heirarchical tree. The tree is also being tracked by an Observer Class which gets passed user input from the Client
 
 > ## Phase III
 > You will need to schedule two check-in's with the TA (during lab hours or office hours) where your entire group will meet with them and discuss:
 > * What you have each done up to this point
 > * What you plan to do until the next meeting (or until the final demo)
 > * If there is anything that is getting in your way
 
 > You may notice that this is effectively a "standup" meeting. We suggest that as a team you have a daily (or every other day) standup, but this will be a bit more formal with the TA. 
 
 > **Your meetings cannot be in the same week of the session so plan ahead**

 > ## Final deliverable
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
