#pragma once
#ifndef INTERFACE_HAMILTONIAN_H
#define INTERFACE_HAMILTONIAN_H
struct State;

// Set the Hamiltonian's parameters
extern "C" void Hamiltonian_Set_Boundary_Conditions(State *state, const bool* periodical, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_mu_s(State *state, float mu_s, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_Field(State *state, float magnitude, const float* normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_Exchange(State *state, int n_shells, const float* jij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_DMI(State *state, float dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_BQE(State *state, float dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_FSC(State *state, float dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_Anisotropy(State *state, float magnitude, const float* normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_STT(State *state, float magnitude, const float * normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Set_Temperature(State *state, float T, int idx_image=-1, int idx_chain=-1);

// Get the Hamiltonian's parameters
extern "C" void Hamiltonian_Get_Boundary_Conditions(State *state, bool * periodical, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_mu_s(State *state, float * mu_s, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_Field(State *state, float * magnitude, float * normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_Exchange(State *state, int * n_shells, float * jij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_Anisotropy(State *state, float * magnitude, float * normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_DMI(State *state, float * dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_BQE(State *state, float * dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_FSC(State *state, float * dij, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_STT(State *state, float * magnitude, float * normal, int idx_image=-1, int idx_chain=-1);
extern "C" void Hamiltonian_Get_Temperature(State *state, float * T, int idx_image=-1, int idx_chain=-1);

// Other
extern "C" bool Hamiltonian_Is_Isotropic(State * state, int idx_image=-1, int idx_chain=-1);

#endif