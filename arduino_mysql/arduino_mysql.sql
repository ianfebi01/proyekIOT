-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 07, 2021 at 04:53 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `arduino_mysql`
--

-- --------------------------------------------------------

--
-- Table structure for table `arduino_data`
--

CREATE TABLE `arduino_data` (
  `id` int(6) UNSIGNED NOT NULL,
  `variabel` varchar(30) NOT NULL,
  `nilai` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `arduino_data`
--

INSERT INTO `arduino_data` (`id`, `variabel`, `nilai`) VALUES
(1, 'dariArduino', '186414'),
(2, 'dariArduino', '2538'),
(3, 'dariArduino', '227525');

-- --------------------------------------------------------

--
-- Table structure for table `browser_data`
--

CREATE TABLE `browser_data` (
  `id` int(6) UNSIGNED NOT NULL,
  `variabel` varchar(30) NOT NULL,
  `nilai` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `arduino_data`
--
ALTER TABLE `arduino_data`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `browser_data`
--
ALTER TABLE `browser_data`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `arduino_data`
--
ALTER TABLE `arduino_data`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `browser_data`
--
ALTER TABLE `browser_data`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
