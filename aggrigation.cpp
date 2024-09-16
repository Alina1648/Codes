#include <iostream>
#include <vector>
class Project {
public:
    Project(std::string n) : name(n) {}
    void showName() const {
        std::cout << "Project Name: " << name << std::endl;
    }
private:
    std::string name;
};
class Department {
public:
    void addProject(Project* p) {
        projects.push_back(p);
    }
    void showProjects() const {
        for (const auto& project : projects) {
            project->showName();
        }
    }
private:
    std::vector<Project*> projects;  // Aggregation: Department has Projects
};
int main() {
    Project project1("Project X");
    Project project2("Project Y");
    Department myDepartment;
    myDepartment.addProject(&project1);
    myDepartment.addProject(&project2);
    myDepartment.showProjects();  // Display all projects in the department
    return 0;
}

