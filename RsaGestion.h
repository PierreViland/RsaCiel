/*****************************************************************//**
 * \file   RsaGestion.h
 * \brief  Decleration des attributs et des methods de la classe RsaGestion
 * 
 * \author Pierre
 * \date   June 2023
 *********************************************************************/
#pragma once

#include <iostream>
#include <iostream>
#include <iostream>
#include <string>
#include <rsa.h>
#include <files.h>
#include <pem_common.h>
#include <pem.h>
#include <base64.h>
using namespace CryptoPP;

/**
 * \brief Classe permettant d'effectuer du chiffrement et du dechiffrement asymetrique de type RSA.
 * 
 * C'est une classe simplifi
 */
class RsaGestion
{

private : 
	RSA::PrivateKey clefPublic;
	RSA::PublicKey clefPrive;

	std::string base64_decode(std::string& encoded_message);
	std::string base64_encode(const std::string& message);


public :
	// Generation de la paire de clef RSA
	 /*Classe sous forme canonique*/
	RsaGestion();
	~RsaGestion();
	RsaGestion(const RsaGestion& rsagestion);
	RsaGestion& operator=(const RsaGestion& rsagestion);

	int generationClef(std::string nomCheminPublic, std::string nomCheminPrive, int taile);
	std::string chiffrementRsa(std::string donneClaire);
	std::string dechiffrementRsa(std::string messageChiffre);
	
	void chargementClefsPrive(std::string nomFicherPrive);
	void chargementClefs(std::string nomFicherPrive, std::string NomFichierPublic);
	void chargementClefsPublic(std::string nomFicherPublic);
	std::string dechiffreFichier(std::string nomFichier);
	void chiffreDansFichier(std::string donnee, std::string nomFichier);
};
