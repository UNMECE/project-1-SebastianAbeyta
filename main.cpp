#include <iostream>
#include <math.h>
using namespace std;

struct _capacitor
{
  double *time;       // time array
  double *voltage;    // voltage array
  double *current;    // current array
  double C;           // capacitance value
};
typedef struct _capacitor Capacitor;

int main()
{
  int time_steps = 50000;
  int i;

  double dt = pow(10,-10);
  double ft = 5*pow(10, -10);
  double R = 1000;
  double C = 100*pow(10, -12);
  double current_supply = 0.01;
  double voltage_supply = 10;

  Capacitor *capacitor = (Capacitor *) malloc(sizeof(Capacitor));

  capacitor->time = (double *) malloc(sizeof(double) * time_steps);
  capacitor->voltage = (double *) malloc(sizeof(double) * time_steps);
  capacitor->current = (double *) malloc(sizeof(double) * time_steps);

  capacitor->voltage[0] = 10;
  capacitor->current[0] = 0.01;
  capacitor->C = 100*pow(10, -12);

  for ( i = 0; i < time_steps + 1; i++)
  {
    capacitor->time[i] = dt * i;   
  }

  for (i = 0; i < time_steps; i++)
  {
    capacitor->time[i] = i;
    capacitor->current[i + 1] = capacitor->current[i] - ((capacitor->current[i] * dt)/(R * capacitor->C));
    capacitor->voltage[i + 1] = capacitor->voltage[i] + (capacitor->current[i] * dt)/capacitor->C;

    if( i % 200 == 0)
    {
      cout << "Time: " << capacitor->time[i] << "s \n";
      cout << "Voltage: " << capacitor->voltage[i] << "V \n";
      cout << "Current: " << capacitor->current[i] << "A \n\n";
    }
  }

  for (i = 0; i < time_steps + 1; i += 200)
  {
    delete[] capacitor->current;
    delete[] capacitor->voltage;
    delete[] capacitor->time; 
  }

  return 0;
}
