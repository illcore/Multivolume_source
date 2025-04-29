//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1PrimaryGeneratorAction.cc
/// \brief Implementation of the B1PrimaryGeneratorAction class

#include "B1PrimaryGeneratorAction.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4RandomDirection.hh"
#include <iostream>
using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1PrimaryGeneratorAction::B1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
//  fEnvelopeBox(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="gamma");
  fParticleGun->SetParticleDefinition(particle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1PrimaryGeneratorAction::~B1PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  G4double Energy;
  G4double Energy1=1.173*MeV;
  G4double Energy2=1.332*MeV;

  G4double pseudo = G4UniformRand();
  if(pseudo > 0 && pseudo <= 0.5){
  Energy=Energy1;
  }
  if(pseudo > 0.5 && pseudo <= 1){
  Energy=Energy2;
  }
  fParticleGun->SetParticleEnergy(Energy);
  G4double psi = G4UniformRand();
// Randomize the direction
G4ThreeVector randomDirection = G4RandomDirection();
//Source I  
  if (psi > 0.0 && psi <= 0.125){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= -36*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source II  
  if (psi > 0.125 && psi <= 0.250){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= -27*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source III  
  if (psi > 0.250 && psi <= 0.375){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= -18*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source IV 
  if (psi > 0.375 && psi <= 0.50){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= -9*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source V  
  if (psi > 0.50 && psi <= 0.625){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= 0*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source VI
  if (psi > 0.625 && psi <= 0.750){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= 9*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source VII 
  if (psi > 0.750 && psi <= 0.875){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= 18*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }
//Source VIII 
  if (psi > 0.875 && psi <= 1){
  G4double x;
  x= -7.5*cm + 15*G4UniformRand()*cm;
  G4double y;
  y= 27*cm + 9*G4UniformRand()*cm; 
  G4double z;
  z= -7.5*cm + 15*G4UniformRand()*cm;
  fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
  fParticleGun->SetParticleMomentumDirection(randomDirection);
  }                                                        
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

