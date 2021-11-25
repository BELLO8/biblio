-- MySQL dump 10.13  Distrib 5.6.48, for Linux (x86_64)
--
-- Host: localhost    Database: Biblio
-- ------------------------------------------------------
-- Server version	5.6.48

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `adherant`
--

DROP TABLE IF EXISTS `adherant`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `adherant` (
  `id_adh` int(11) NOT NULL AUTO_INCREMENT,
  `nom_adh` varchar(255) DEFAULT NULL,
  `prenom` varchar(255) DEFAULT NULL,
  `code_emp` int(11) NOT NULL,
  PRIMARY KEY (`id_adh`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `adherant`
--

LOCK TABLES `adherant` WRITE;
/*!40000 ALTER TABLE `adherant` DISABLE KEYS */;
INSERT INTO `adherant` VALUES (1,'Kader','Ade',1234),(2,'ALI','BABA',4444),(3,'Linux','Kali',5555),(4,'ELI','PERT',2222);
/*!40000 ALTER TABLE `adherant` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emprunter`
--

DROP TABLE IF EXISTS `emprunter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emprunter` (
  `id_emp` int(11) NOT NULL AUTO_INCREMENT,
  `code_emp_adh` int(11) DEFAULT NULL,
  `id_livre` int(11) DEFAULT NULL,
  `date_emp` datetime DEFAULT NULL,
  `deposer` varchar(8) NOT NULL,
  `date_dep` datetime DEFAULT NULL,
  PRIMARY KEY (`id_emp`),
  UNIQUE KEY `ind_unique` (`code_emp_adh`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emprunter`
--

LOCK TABLES `emprunter` WRITE;
/*!40000 ALTER TABLE `emprunter` DISABLE KEYS */;
INSERT INTO `emprunter` VALUES (1,1234,1,'2021-04-02 20:03:57','oui','2021-04-02 20:32:26'),(6,4444,1,'2021-04-02 20:10:22','oui','2021-04-08 11:11:03'),(11,5555,3,'2021-04-02 20:19:45','oui','2021-04-02 20:33:14'),(12,2222,2,'2021-04-02 20:20:37','oui','2021-04-02 20:33:41');
/*!40000 ALTER TABLE `emprunter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `livre`
--

DROP TABLE IF EXISTS `livre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `livre` (
  `id_livre` int(11) NOT NULL AUTO_INCREMENT,
  `titre` varchar(255) DEFAULT NULL,
  `annee_parution` date DEFAULT NULL,
  PRIMARY KEY (`id_livre`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `livre`
--

LOCK TABLES `livre` WRITE;
/*!40000 ALTER TABLE `livre` DISABLE KEYS */;
INSERT INTO `livre` VALUES (1,'java','2000-06-23'),(2,'UML','2000-08-22'),(3,'JAVA','2002-12-03');
/*!40000 ALTER TABLE `livre` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-11 10:11:49
