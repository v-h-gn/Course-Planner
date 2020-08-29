
# BCOE Course Planner
 > Authors: [Vahagn Tovmasian](https://github.com/Varhagna) [Selma Kondoker](https://github.com/skondoker)

## Project Description
 
 The BCOE Course Planner will be a course planning software for UCR students within the College of Engineering
 In our experience, showing prospective students the course plan and talking to them about how useful, as well as using it ourselves has shown us the benefits of a good course plan. We want to extend that tool but generate a custom course plan depending on conditions inputted by the user.
 
 This project is written in C++. We originally intended to use a library to parse through the Catalog PDF however this ended up being extremely difficult, so through a combination of manual labor, tools such as the Find + Replace tool build into our IDEs, as well as basic regex, we formatted the courses into a single resource file. Due to the time consuming nature of this, at the moment the application will only work with BCOE majors. We intend to add more majors as we go however as we develop a more sophisticated parse of the PDF.

We utilise several design patterns in order to optimize our handling of objects and simplify our code.

  * Abstract factory creational pattern to create families of classes from the course catalog.
  * Composite structural pattern to create our class tree and indicate hierarchies with pre-requisites.
  * Observer behavioral pattern to handle and update changes made to the course schedule.
  
We intend to add more as we extend functionality such as we add a more beautiful command line interface, potentially a GUI, [Graphviz](https://graphviz.org/) integration, Regex parsing of the Catalog PDF etc.
 
  The Course Planner will intend at basic to take in any student specific information such as credits completed, courses taken and passed, expected or planned graduation date, which will create a customized course plan they can follow as they progress through their degree.

 
## Class Diagram

   ![Class Diagram](https://i.imgur.com/SUe78qX.png)
   
   Our diagram illustrates a Client which uses the Abstract Factory Pattern to utilise a PDF Parser to read through and construct different Components which can then be constructed into a heirarchical tree. The tree is also being tracked by an Observer Class which gets passed user input from the Client.

 ## Screenshots
  
 ![Image of Main](https://i.imgur.com/eFtBBNf.png)
 Here you can see the currently implemented debug messages which show how the graph is being built.
 
 ![Image of Main2](https://i.imgur.com/x0yg32r.png)
 Here you can see how it prompts the user to pick a class to remove from the graph, but at the moment this doesn't function as intended.
 
 ## Installation/Usage
 
 The BCOE Course Planner can only be confirmed to function on Windows 10. It has yet to be tested on other OS.
 
 In order to install our application, simply download the exe file via our GitHub releases. At the moment the current release doesn't have any binaries for download, but once the application gets to a usable state you should be able to download it by clicking on the release.
 
To run the application simply open the exe file and type in all related information. You will be prompted to type in certain things at specific points during the execution process via the program.
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
 We utilised the [Google Test Framework](https://github.com/google/googletest) in order to test our project. At the moment our testing suite is rather limited but we intend upon adding Continuous Integration via GitHub actions to our repository to automatically build validate our source code. The current test suite checks that no exceptions occur during run time for some of our methods. The test harnesses shall be improved as we go back and optimize our code so that it can be more readable, testable, and performant.
