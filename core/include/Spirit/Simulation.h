#pragma once
#ifndef INTERFACE_SIMULATION_H
#define INTERFACE_SIMULATION_H
#include "DLL_Define_Export.h"

struct State;

#include <vector>

#define Solver_VP          0
#define Solver_SIB         1
#define Solver_Depondt     2
#define Solver_Heun        3
#define Solver_RungeKutta4 4

// Start a simulation
PREFIX void Simulation_MC_Start(State *state, int n_iterations=-1, int n_iterations_log=-1,
    bool singleshot=false, int idx_image=-1, int idx_chain=-1) SUFFIX;

PREFIX void Simulation_LLG_Start(State *state, int solver_type, int n_iterations=-1, int n_iterations_log=-1,
    bool singleshot=false, int idx_image=-1, int idx_chain=-1) SUFFIX;

PREFIX void Simulation_GNEB_Start(State *state, int solver_type, int n_iterations=-1, int n_iterations_log=-1,
    bool singleshot=false, int idx_chain=-1) SUFFIX;

PREFIX void Simulation_MMF_Start(State *state, int solver_type, int n_iterations=-1, int n_iterations_log=-1,
    bool singleshot=false, int idx_image=-1, int idx_chain=-1) SUFFIX;

PREFIX void Simulation_EMA_Start(State *state, int n_iterations=-1, int n_iterations_log=-1,
    bool singleshot=false, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Single iteration of a Method
//  If singleshot=true was passed to Simulation_..._Start before, this will perform one iteration.
//  Otherwise, nothing will happen.
PREFIX void Simulation_SingleShot(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Stop a simulation running on an image or chain
PREFIX void Simulation_Stop(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Stop all simulations
PREFIX void Simulation_Stop_All(State *state) SUFFIX;


// Get maximum torque component
//      If a MC, LLG, MMF or EMA simulation is running this returns the max. torque on the current image.
//      If a GNEB simulation is running this returns the max. torque on the current chain.
PREFIX float Simulation_Get_MaxTorqueComponent(State * state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get maximum torque components on the images of a chain
//      Will only work if a GNEB simulation is running.
PREFIX void Simulation_Get_Chain_MaxTorqueComponents(State * state, float * torques, int idx_chain=-1) SUFFIX;

// Get IPS
//      If a MC, LLG, MMF or EMA simulation is running this returns the IPS on the current image.
//      If a GNEB simulation is running this returns the IPS on the current chain.
PREFIX float Simulation_Get_IterationsPerSecond(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get number of done iterations
PREFIX int Simulation_Get_Iteration(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get time passed by the simulation in picoseconds
//      If an LLG simulation is running this returns the cumulatively summed dt.
//      Otherwise it returns 0.
PREFIX float Simulation_Get_Time(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get number of miliseconds since the simulation was started
PREFIX int Simulation_Get_Wall_Time(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get name of the currently used method
//      If a MC, LLG, MMF or EMA simulation is running this returns the Solver name on the current image.
//      If a GNEB simulation is running this returns the Solver name on the current chain.
PREFIX const char * Simulation_Get_Solver_Name(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;

// Get name of the currently used method
//      If a MC, LLG, MMF or EMA simulation is running this returns the Method name on the current image.
//      If a GNEB simulation is running this returns the Method name on the current chain.
PREFIX const char * Simulation_Get_Method_Name(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;


// Check if a simulation is running on specific image of specific chain
PREFIX bool Simulation_Running_On_Image(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;
// Check if a simulation is running across a specific chain
PREFIX bool Simulation_Running_On_Chain(State *state, int idx_chain=-1) SUFFIX;

// Check if a simulation is running on any or all images of a chain
PREFIX bool Simulation_Running_Anywhere_On_Chain(State *state, int idx_chain=-1) SUFFIX;

#include "DLL_Undefine_Export.h"
#endif
