#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// VIOLACIÓN: Uso indiscriminado de using namespace std
// VIOLACIÓN: Sin guards de header, todo en un archivo

#define MAX 100  // VIOLACIÓN: Macros en vez de constantes
#define PI 3.14

// VIOLACIÓN: Variables globales por todas partes
int globalCounter = 0;
vector<string> logs;
bool debugMode = true;
string DB_FILE = "data.txt";

// VIOLACIÓN: Clase con TODO público, sin encapsulamiento
class e {
public:
    string n;  // name
    int a;     // age
    double s;  // salary
    int t;     // type: 1=dev, 2=manager, 3=designer, 4=tester
    vector<string> p;  // projects
    string* addr;  // VIOLACIÓN: Puntero crudo sin gestión
    bool active;
    int daysOff;
    double* bonusHistory;  // VIOLACIÓN: Array dinámico sin control de tamaño
    int bonusCount;
    
    // VIOLACIÓN: Constructor que puede fallar sin forma de reportarlo
    e(string nn, int aa, double ss, int tt) {
        n=nn;a=aa;s=ss;t=tt;
        active=true;daysOff=0;
        addr = new string("Unknown");  // VIOLACIÓN: memoria dinámica sin delete
        bonusHistory = new double[10];  // VIOLACIÓN: tamaño fijo arbitrario
        bonusCount=0;
        globalCounter++;  // VIOLACIÓN: Efecto secundario en constructor
    }
    
    // VIOLACIÓN: Destructor ausente = memory leak
    
    // VIOLACIÓN: Función larga que hace MUCHAS cosas diferentes
    // VIOLACIÓN: Múltiples niveles de indentación
    // VIOLACIÓN: Mezcla de responsabilidades
    double calc(bool print, bool save, string file) {
        double b=0;
        double tax=0;
        double net=0;
        
        // VIOLACIÓN: Lógica de negocio compleja sin extraer
        if(t==1) {
            b=s*0.1;
            if(p.size()>5)b+=500;
            if(p.size()>10)b+=1000;
            if(a>30)b+=200;
            if(a>40)b+=400;
            // VIOLACIÓN: Cálculo complejo inline
            for(int i=0;i<p.size();i++){
                if(p[i].length()>10)b+=50;
            }
        } else if(t==2) {
            b=s*0.15;
            if(a>40)b+=1000;
            if(a>50)b+=2000;
            // VIOLACIÓN: Código duplicado
            for(int i=0;i<p.size();i++){
                if(p[i].length()>10)b+=50;
            }
        } else if(t==3) {
            b=s*0.08;
            if(p.size()>3)b+=300;
            // VIOLACIÓN: Más duplicación
            for(int i=0;i<p.size();i++){
                if(p[i].length()>10)b+=50;
            }
        } else if(t==4) {
            b=s*0.05;
            // VIOLACIÓN: Magic numbers
            if(daysOff<5)b+=100;
        } else {
            // VIOLACIÓN: Sin manejo de caso inválido
            b=0;
        }
        
        // VIOLACIÓN: Cálculo de impuestos mezclado con bonos
        // VIOLACIÓN: Lógica compleja sin abstracción
        if(s<30000){
            tax=s*0.1;
            if(b>1000)tax+=b*0.05;
        }else if(s>=30000&&s<60000){
            tax=s*0.15;
            if(b>1000)tax+=b*0.08;
        }else if(s>=60000&&s<100000){
            tax=s*0.2;
            if(b>1000)tax+=b*0.1;
            if(a>50)tax-=500;  // VIOLACIÓN: Regla de negocio escondida
        }else{
            tax=s*0.25;
            if(b>1000)tax+=b*0.12;
            if(a>50)tax-=500;
        }
        
        net=s+b-tax;
        
        // VIOLACIÓN: Guardar el bono (efecto secundario no obvio)
        if(bonusCount<10) {
            bonusHistory[bonusCount++]=b;
        }
        
        // VIOLACIÓN: Parámetro booleano que cambia comportamiento
        if(print) {
            cout<<"=== CALCULATION RESULTS ==="<<endl;
            cout<<"Base Salary: "<<s<<endl;
            cout<<"Bonus: "<<b<<endl;
            cout<<"Tax: "<<tax<<endl;
            cout<<"Net Salary: "<<net<<endl;
            cout<<"=========================="<<endl;
            
            // VIOLACIÓN: Log a variable global
            logs.push_back("Calculated for " + n);
        }
        
        // VIOLACIÓN: Otro parámetro booleano
        if(save) {
            // VIOLACIÓN: Manejo de archivos sin try/catch
            // VIOLACIÓN: Uso del parámetro file mezclado con lógica
            ofstream f;
            f.open(file, ios::app);
            f<<n<<","<<s<<","<<b<<","<<tax<<","<<net<<"\n";
            f.close();  // VIOLACIÓN: ¿Qué pasa si falla?
        }
        
        return net;  // VIOLACIÓN: Función llamada "calc" retorna "net"
    }
    
    // VIOLACIÓN: Función con demasiados parámetros
    void update(string newName, int newAge, double newSal, int newType, bool isActive, int days, string newAddr) {
        n=newName;
        a=newAge;
        s=newSal;
        t=newType;
        active=isActive;
        daysOff=days;
        *addr=newAddr;
        // VIOLACIÓN: Sin validación de datos
    }
    
    // VIOLACIÓN: Nombres inconsistentes (printInfo vs calc vs update)
    void printInfo() {
        cout<<"Name: "<<n<<" | Age: "<<a<<" | Salary: $"<<s<<" | ";
        
        // VIOLACIÓN: Switch/if que debería ser polimorfismo
        if(t==1)cout<<"Type: Developer";
        else if(t==2)cout<<"Type: Manager";
        else if(t==3)cout<<"Type: Designer";
        else if(t==4)cout<<"Type: Tester";
        else cout<<"Type: Unknown";  // VIOLACIÓN: Caso de error silencioso
        
        cout<<" | Status: "<<(active?"Active":"Inactive");
        cout<<" | Days Off: "<<daysOff;
        cout<<" | Address: "<<*addr<<endl;
        
        if(p.size()>0) {
            cout<<"Projects ("<<p.size()<<"): ";
            for(int i=0;i<p.size();i++) {
                cout<<p[i];
                if(i<p.size()-1)cout<<", ";
            }
            cout<<endl;
        }
        
        // VIOLACIÓN: Mezclar presentación con lógica de negocio
        if(bonusCount>0) {
            double total=0;
            for(int i=0;i<bonusCount;i++)total+=bonusHistory[i];
            cout<<"Avg Bonus History: $"<<total/bonusCount<<endl;
        }
    }
    
    // VIOLACIÓN: Función que retorna código de error en vez de excepciones
    int addProject(string proj) {
        if(proj.length()==0)return -1;  // VIOLACIÓN: Magic number para error
        if(proj.length()>50)return -2;
        if(p.size()>=20)return -3;  // VIOLACIÓN: Límite arbitrario
        p.push_back(proj);
        return 0;  // VIOLACIÓN: 0 = success, confuso
    }
    
    // VIOLACIÓN: Función que modifica Y retorna (comando + query)
    double applyRaise(double percent) {
        s = s + (s * percent / 100);
        return s;
    }
};

// VIOLACIÓN: Función global gigante que hace TODO
// VIOLACIÓN: Parámetros de salida por referencia mezclados con entrada
void processEmployees(vector<e>& emps, string op, int& totalProcessed, bool& hasError) {
    hasError = false;
    
    // VIOLACIÓN: Estructura gigante if/else en vez de polimorfismo o map
    if(op=="add"||op=="ADD"||op=="a") {  // VIOLACIÓN: Múltiples formas de invocar
        string name;int age;double sal;int type;string address;
        
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin, name);
        
        // VIOLACIÓN: Sin validación de entrada
        cout<<"Enter age: ";cin>>age;
        cout<<"Enter salary: ";cin>>sal;
        cout<<"Enter type (1=dev,2=mgr,3=des,4=test): ";cin>>type;
        cout<<"Enter address: ";
        cin.ignore();
        getline(cin, address);
        
        e newE(name,age,sal,type);
        *newE.addr = address;
        emps.push_back(newE);
        
        // VIOLACIÓN: Código duplicado de logging
        cout<<"✓ Employee added successfully!"<<endl;
        logs.push_back("Added employee: " + name);
        totalProcessed++;
        
        // VIOLACIÓN: Efecto secundario - guardar automáticamente
        ofstream f(DB_FILE, ios::app);
        f<<name<<","<<age<<","<<sal<<","<<type<<"\n";
        f.close();
        
    } else if(op=="list"||op=="LIST"||op=="l") {
        if(emps.size()==0) {  // VIOLACIÓN: Comparación con 0 en vez de empty()
            cout<<"No employees found."<<endl;
            return;  // VIOLACIÓN: Return temprano sin cleanup
        }
        
        for(int i=0;i<emps.size();i++) {
            cout<<"\n========== Employee #"<<(i+1)<<" =========="<<endl;
            emps[i].printInfo();
            cout<<"======================================"<<endl;
        }
        totalProcessed = emps.size();
        
    } else if(op=="bonus"||op=="BONUS"||op=="b") {
        string saveFile;
        cout<<"Save to file? (filename or 'no'): ";
        cin>>saveFile;
        
        bool shouldSave = (saveFile!="no");
        
        for(int i=0;i<emps.size();i++) {
            cout<<"\n--- Employee: "<<emps[i].n<<" ---"<<endl;
            // VIOLACIÓN: Parámetros confusos
            emps[i].calc(true, shouldSave, saveFile);
            totalProcessed++;
        }
        
    } else if(op=="search"||op=="SEARCH"||op=="s") {
        string searchName;
        cout<<"Enter name to search: ";
        cin.ignore();
        getline(cin, searchName);
        
        bool found=false;
        // VIOLACIÓN: Búsqueda lineal ineficiente
        for(int i=0;i<emps.size();i++) {
            // VIOLACIÓN: Comparación case-sensitive
            if(emps[i].n==searchName) {
                emps[i].printInfo();
                found=true;
                totalProcessed++;
                break;
            }
        }
        
        if(!found) {
            cout<<"❌ Employee not found: "<<searchName<<endl;
            hasError=true;  // VIOLACIÓN: ¿Es realmente un error?
        }
        
    } else if(op=="raise"||op=="RAISE"||op=="r") {
        double percent;
        cout<<"Enter raise percentage: ";
        cin>>percent;
        
        // VIOLACIÓN: Sin validación (¿puede ser negativo?)
        int count=0;
        for(int i=0;i<emps.size();i++) {
            if(emps[i].active) {  // VIOLACIÓN: Lógica de negocio escondida
                double newSal = emps[i].applyRaise(percent);
                count++;
            }
        }
        
        cout<<"✓ Applied "<<percent<<"% raise to "<<count<<" employees"<<endl;
        totalProcessed=count;
        
        // VIOLACIÓN: Log inconsistente
        if(debugMode)cout<<"[DEBUG] Raise operation completed"<<endl;
        
    } else if(op=="avgsal"||op=="average"||op=="avg") {
        // VIOLACIÓN: División por cero no manejada
        double total=0;
        int activeCount=0;
        
        for(int i=0;i<emps.size();i++) {
            if(emps[i].active) {
                total+=emps[i].s;
                activeCount++;
            }
        }
        
        cout<<"Average Salary (active): $"<<total/activeCount<<endl;  // VIOLACIÓN: CRASH si activeCount=0
        totalProcessed=activeCount;
        
    } else if(op=="delete"||op=="DELETE"||op=="d") {
        string delName;
        cout<<"Enter name to delete: ";
        cin.ignore();
        getline(cin, delName);
        
        // VIOLACIÓN: Borrado durante iteración
        for(int i=0;i<emps.size();i++) {
            if(emps[i].n==delName) {
                // VIOLACIÓN: No se libera memoria dinámica
                emps.erase(emps.begin()+i);
                cout<<"✓ Deleted: "<<delName<<endl;
                totalProcessed++;
                return;
            }
        }
        
        cout<<"❌ Not found"<<endl;
        hasError=true;
        
    } else if(op=="export"||op=="EXPORT"||op=="e") {
        // VIOLACIÓN: Hardcoded filename
        ofstream outFile("employees_export.csv");
        
        // VIOLACIÓN: Sin verificar si se abrió correctamente
        outFile<<"Name,Age,Salary,Type,Status,DaysOff\n";
        
        for(int i=0;i<emps.size();i++) {
            outFile<<emps[i].n<<","<<emps[i].a<<","<<emps[i].s<<","
                   <<emps[i].t<<","<<(emps[i].active?"1":"0")<<","
                   <<emps[i].daysOff<<"\n";
        }
        
        outFile.close();
        cout<<"✓ Exported to employees_export.csv"<<endl;
        totalProcessed=emps.size();
        
    } else if(op=="import"||op=="IMPORT"||op=="i") {
        // VIOLACIÓN: Sin manejo de excepciones
        ifstream inFile("employees_import.csv");
        string line;
        
        getline(inFile, line);  // Skip header - VIOLACIÓN: asume que existe
        
        while(getline(inFile, line)) {
            // VIOLACIÓN: Parsing manual propenso a errores
            int pos1=line.find(',');
            int pos2=line.find(',',pos1+1);
            int pos3=line.find(',',pos2+1);
            int pos4=line.find(',',pos3+1);
            
            string name=line.substr(0,pos1);
            int age=stoi(line.substr(pos1+1,pos2-pos1-1));  // VIOLACIÓN: puede lanzar excepción
            double sal=stod(line.substr(pos2+1,pos3-pos2-1));
            int type=stoi(line.substr(pos3+1,pos4-pos3-1));
            
            e newE(name,age,sal,type);
            emps.push_back(newE);
            totalProcessed++;
        }
        
        inFile.close();
        cout<<"✓ Imported "<<totalProcessed<<" employees"<<endl;
        
    } else if(op=="stats"||op=="STATS") {
        // VIOLACIÓN: Cálculos complejos sin extraer a funciones
        int devs=0,mgrs=0,dess=0,tests=0;
        double totalSal=0,minSal=999999,maxSal=0;
        int youngest=999,oldest=0;
        
        for(int i=0;i<emps.size();i++) {
            if(emps[i].t==1)devs++;
            else if(emps[i].t==2)mgrs++;
            else if(emps[i].t==3)dess++;
            else if(emps[i].t==4)tests++;
            
            totalSal+=emps[i].s;
            if(emps[i].s<minSal)minSal=emps[i].s;
            if(emps[i].s>maxSal)maxSal=emps[i].s;
            if(emps[i].a<youngest)youngest=emps[i].a;
            if(emps[i].a>oldest)oldest=emps[i].a;
        }
        
        // VIOLACIÓN: Formato de salida inconsistente
        cout<<"\n╔══════════════════════════╗"<<endl;
        cout<<"║    COMPANY STATISTICS    ║"<<endl;
        cout<<"╚══════════════════════════╝"<<endl;
        cout<<"Total Employees: "<<emps.size()<<endl;
        cout<<"  - Developers: "<<devs<<endl;
        cout<<"  - Managers: "<<mgrs<<endl;
        cout<<"  - Designers: "<<dess<<endl;
        cout<<"  - Testers: "<<tests<<endl;
        cout<<"Average Salary: $"<<totalSal/emps.size()<<endl;
        cout<<"Salary Range: $"<<minSal<<" - $"<<maxSal<<endl;
        cout<<"Age Range: "<<youngest<<" - "<<oldest<<endl;
        
        totalProcessed=1;
        
    } else if(op=="logs"||op=="LOGS") {
        // VIOLACIÓN: Acceso directo a variable global
        cout<<"\n=== System Logs ==="<<endl;
        for(int i=0;i<logs.size();i++) {
            cout<<"["<<i+1<<"] "<<logs[i]<<endl;
        }
        
    } else if(op=="help"||op=="HELP"||op=="h"||op=="?") {
        // VIOLACIÓN: Documentación en código en vez de auto-documentado
        cout<<"\nAvailable commands:"<<endl;
        cout<<"  add/a       - Add new employee"<<endl;
        cout<<"  list/l      - List all employees"<<endl;
        cout<<"  bonus/b     - Calculate bonuses"<<endl;
        cout<<"  search/s    - Search employee"<<endl;
        cout<<"  raise/r     - Apply salary raise"<<endl;
        cout<<"  avgsal/avg  - Calculate average salary"<<endl;
        cout<<"  delete/d    - Delete employee"<<endl;
        cout<<"  export/e    - Export to CSV"<<endl;
        cout<<"  import/i    - Import from CSV"<<endl;
        cout<<"  stats       - Show statistics"<<endl;
        cout<<"  logs        - Show system logs"<<endl;
        cout<<"  exit/quit   - Exit program"<<endl;
        
    } else {
        // VIOLACIÓN: Mensaje de error poco útil
        cout<<"??? Unknown command: "<<op<<endl;
        cout<<"Type 'help' for available commands"<<endl;
        hasError=true;
    }
    
    // VIOLACIÓN: Log global al final de cada operación
    if(debugMode && !hasError) {
        cout<<"[DEBUG] Operation '"<<op<<"' completed. Processed: "<<totalProcessed<<endl;
    }
}

// VIOLACIÓN: Función main demasiado larga
// VIOLACIÓN: Lógica de aplicación mezclada con UI
int main() {
    vector<e> employees;
    int totalOps = 0;
    
    // VIOLACIÓN: ASCII art innecesario
    cout<<"╔════════════════════════════════════════╗"<<endl;
    cout<<"║   EMPLOYEE MANAGEMENT SYSTEM v1.0      ║"<<endl;
    cout<<"║   (Terrible Code Edition)              ║"<<endl;
    cout<<"╚════════════════════════════════════════╝"<<endl;
    
    // VIOLACIÓN: Datos hardcodeados de prueba
    e e1("John Doe",30,50000,1);
    e1.p.push_back("Project Alpha");
    e1.p.push_back("Project Beta");
    e1.p.push_back("Project Gamma");
    *e1.addr = "123 Main St";
    employees.push_back(e1);
    
    e e2("Mary Smith",45,80000,2);
    e2.p.push_back("Management Dashboard");
    *e2.addr = "456 Oak Ave";
    e2.daysOff = 3;
    employees.push_back(e2);
    
    e e3("Bob Johnson",28,45000,3);
    *e3.addr = "789 Pine Rd";
    employees.push_back(e3);
    
    e e4("Alice Williams",35,55000,4);
    e4.active = false;  // VIOLACIÓN: Estado inconsistente
    employees.push_back(e4);
    
    logs.push_back("System started");
    logs.push_back("Loaded " + to_string(employees.size()) + " sample employees");
    
    string cmd;
    int processed;
    bool error;
    
    // VIOLACIÓN: Loop infinito con break escondido
    while(true) {
        processed = 0;
        error = false;
        
        cout<<"\n> ";
        cin>>cmd;
        
        // VIOLACIÓN: Múltiples formas de salir
        if(cmd=="exit"||cmd=="quit"||cmd=="q"||cmd=="EXIT"||cmd=="QUIT") {
            // VIOLACIÓN: Sin cleanup de memoria dinámica
            cout<<"Goodbye! Total operations: "<<totalOps<<endl;
            break;
        }
        
        // VIOLACIÓN: Try-catch que captura TODO genéricamente
        try {
            processEmployees(employees, cmd, processed, error);
            totalOps++;
        } catch(...) {
            // VIOLACIÓN: Catch genérico sin información
            cout<<"💥 Something went wrong!"<<endl;
            error = true;
        }
        
        // VIOLACIÓN: Lógica de negocio en main
        if(totalOps % 10 == 0 && totalOps > 0) {
            cout<<"\n🎉 You've performed "<<totalOps<<" operations!"<<endl;
        }
    }
    
    // VIOLACIÓN: No se ejecuta nunca (unreachable después de break)
    cout<<"This will never print"<<endl;
    
    return 0;
}
