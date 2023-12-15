-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 19, 2023 at 03:05 PM
-- Server version: 10.4.25-MariaDB
-- PHP Version: 7.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sport_inventory`
--

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `inventory_id` int(11) NOT NULL,
  `item_id` int(11) DEFAULT NULL,
  `staff_id` int(11) DEFAULT NULL,
  `in_quantity` int(50) DEFAULT NULL,
  `out_quantity` int(50) DEFAULT NULL,
  `current_quantity` int(50) DEFAULT NULL,
  `CheckDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`inventory_id`, `item_id`, `staff_id`, `in_quantity`, `out_quantity`, `current_quantity`, `CheckDate`) VALUES
(6, 34, 1, 34, 2, 17, '2023-01-07'),
(7, 46, 1, 0, 0, 21, '2023-02-02'),
(9, 45, 1, 0, 0, 25, '2023-03-29'),
(10, 48, 1, 0, 0, 26, '2023-04-04'),
(11, 51, 1, 10, 0, 40, '2023-01-03'),
(12, 49, 1, 10, 0, 50, '2023-01-01'),
(13, 57, 1, 10, 10, 35, '2023-01-16');

-- --------------------------------------------------------

--
-- Table structure for table `item`
--

CREATE TABLE `item` (
  `item_id` int(11) NOT NULL,
  `staff_id` int(11) DEFAULT NULL,
  `item_name` varchar(20) DEFAULT NULL,
  `type` varchar(20) DEFAULT NULL,
  `brand` varchar(20) DEFAULT NULL,
  `price_per_item` int(11) DEFAULT NULL,
  `item_description` varchar(20) DEFAULT NULL,
  `supplier` varchar(25) DEFAULT NULL,
  `current_quantity` int(50) DEFAULT NULL,
  `quantitytoreorder` int(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `item`
--

INSERT INTO `item` (`item_id`, `staff_id`, `item_name`, `type`, `brand`, `price_per_item`, `item_description`, `supplier`, `current_quantity`, `quantitytoreorder`) VALUES
(27, 1, 'hotshot', 'slipper', 'puma', 99, 'for men', 'noni', 26, 0),
(34, 2, 'supreme', 'shoes', 'adidas', 199, 'shoes', 'noni', 20, 0),
(43, 1, 'GHOSTX', 'SHOES', 'ADIDAS', 499, 'RUNNING SHOES', 'EVE', 24, 10),
(45, 1, 'hotshot', 'slipper', 'puma', 99, 'for men', 'noni', 25, 0),
(46, 1, 'PSG Jersey', 'jersey', 'Jordan', 299, 'homekit', 'eve', 21, 10),
(47, 1, 'Liverpool Kit', 'Jersey', 'Adidas', 169, 'fans issue', 'eve', 25, 10),
(48, 1, 'Liverpool AwayKit', 'Jersey', 'Adidas', 238, 'Player Issue', 'eve', 26, 10),
(49, 1, 'White Lines', 'stockings', 'Puma', 69, 'stockings', 'rose', 50, 10),
(50, 1, 'Argentina AwayKit', 'jersey', 'Adidas', 269, 'player issue', 'eve', 29, 10),
(51, 1, 'Golden X ', 'Boots', 'Jeep', 346, 'Boots', 'noni', 50, 10),
(55, 1, 'Adidas Predator', 'Boots', 'Adidas', 249, 'Next-gen', 'noni', 35, 0),
(57, 1, 'Reebok Pants', 'Pants', 'Reebok', 100, 'pants', 'rose', 42, 0),
(59, 1, 'Jordan Air', 'Sneakers', 'Nike', 700, 'Sneakers', 'rose', 40, 20),
(61, 1, 'HighCut', 'Boots', 'NewBalance', 344, 'Boots', 'noni', 40, 10);

-- --------------------------------------------------------

--
-- Table structure for table `order`
--

CREATE TABLE `order` (
  `order_id` int(11) NOT NULL,
  `staff_id` int(11) DEFAULT NULL,
  `supplier_id` int(11) DEFAULT NULL,
  `item_name` varchar(20) DEFAULT NULL,
  `date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `order`
--

INSERT INTO `order` (`order_id`, `staff_id`, `supplier_id`, `item_name`, `date`) VALUES
(1, 1, 8, 'adidas', '2022-01-01'),
(2, 1, 8, 'supreme', '2023-01-01'),
(7, 1, 8, 'slipper', '2023-01-11'),
(8, 1, 8, 'supreme', '2023-01-10'),
(19, 1, 8, 'Golden X', '2023-01-11'),
(20, 1, 8, 'supreme', '2023-01-08'),
(24, 1, 10, 'White Lines', '2023-01-10'),
(25, 1, 8, 'Astrox 99', '2023-01-11'),
(27, 1, 10, 'Reebok Pants', '2023-01-16'),
(28, 1, 10, 'HighCut', '2023-01-19'),
(29, 1, 10, 'Jordan Air', '2023-01-16'),
(36, 1, 8, 'Adidas Predator', '2023-01-14'),
(57, 1, 10, 'Pants', '2023-01-17');

-- --------------------------------------------------------

--
-- Table structure for table `order_list`
--

CREATE TABLE `order_list` (
  `order_itemid` int(11) NOT NULL,
  `order_id` int(11) DEFAULT NULL,
  `item_id` int(11) NOT NULL,
  `OrderItemQty` int(50) DEFAULT NULL,
  `status` varchar(50) DEFAULT NULL,
  `ReceivedDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `order_list`
--

INSERT INTO `order_list` (`order_itemid`, `order_id`, `item_id`, `OrderItemQty`, `status`, `ReceivedDate`) VALUES
(1, 1, 27, 1, 'available', '2023-01-01'),
(3, 19, 51, 1, 'AVAILABLE', '2023-01-02'),
(7, 7, 46, 6, 'AVAILABLE', '2021-02-12'),
(11, 8, 34, 12, 'AVAILABLE', '2023-01-08'),
(12, 1, 27, 1, 'available', '2023-01-01'),
(13, 7, 34, 2, 'available', '2023-01-08'),
(15, 2, 43, 2, 'available', '2023-01-08'),
(16, 27, 57, 10, 'AVAILABLE', '2023-01-16'),
(17, 27, 49, 6, 'AVAILABLE', '2023-01-17'),
(18, 57, 57, 20, 'AVAILABLE', '2023-01-17'),
(20, 28, 61, 10, 'AVAILABLE', '2023-01-19'),
(59, 29, 59, 20, 'AVAILABLE', '2023-01-16');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `staff_id` int(11) NOT NULL,
  `username` varchar(20) DEFAULT NULL,
  `password` varchar(20) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `contact_no` varchar(20) DEFAULT NULL,
  `age` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`staff_id`, `username`, `password`, `name`, `contact_no`, `age`) VALUES
(1, 'auni', 'auni', 'auni', '01239485219', 21),
(2, 'sya', '123', 'auni', '01151641079', 21),
(3, 'atiqa', 'atiqa', 'tiqa', '0192837451', 36),
(5, 'pxie', '12345', 'pxie', '0192831442', 34),
(6, 'sarah', '12345', 'sarah', '0129482145', 26);

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE `supplier` (
  `supplier_id` int(11) NOT NULL,
  `username` varchar(20) DEFAULT NULL,
  `password` varchar(20) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `phone` varchar(20) DEFAULT NULL,
  `company` varchar(20) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`supplier_id`, `username`, `password`, `name`, `phone`, `company`, `email`, `address`) VALUES
(8, 'noni', '1234', 'noni', '0193874591', 'adidas', 'noni@gmail.com', 'st.borough 17/3, London'),
(9, 'rose', '123', 'ad', '01151641079', 'niky', 'ad', 'kg batu 2'),
(10, 'eve', 'eve', 'eve', '0192832304', 'beat', 'eve@yahoo.com', 'st 34 London'),
(11, 'sara', '12345', 'sara', '019232145', 'jd', 'mia@gmail.com', 'taman tasik singgah');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`inventory_id`),
  ADD KEY `item_id` (`item_id`),
  ADD KEY `staff_id` (`staff_id`);

--
-- Indexes for table `item`
--
ALTER TABLE `item`
  ADD PRIMARY KEY (`item_id`),
  ADD KEY `staff_id` (`staff_id`);

--
-- Indexes for table `order`
--
ALTER TABLE `order`
  ADD PRIMARY KEY (`order_id`),
  ADD KEY `staff_id` (`staff_id`),
  ADD KEY `supplier_id` (`supplier_id`);

--
-- Indexes for table `order_list`
--
ALTER TABLE `order_list`
  ADD PRIMARY KEY (`order_itemid`),
  ADD KEY `order_id` (`order_id`),
  ADD KEY `item_id` (`item_id`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`staff_id`);

--
-- Indexes for table `supplier`
--
ALTER TABLE `supplier`
  ADD PRIMARY KEY (`supplier_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `inventory`
--
ALTER TABLE `inventory`
  MODIFY `inventory_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `item`
--
ALTER TABLE `item`
  MODIFY `item_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=63;

--
-- AUTO_INCREMENT for table `order`
--
ALTER TABLE `order`
  MODIFY `order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=58;

--
-- AUTO_INCREMENT for table `order_list`
--
ALTER TABLE `order_list`
  MODIFY `order_itemid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=60;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `staff_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `supplier`
--
ALTER TABLE `supplier`
  MODIFY `supplier_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `inventory`
--
ALTER TABLE `inventory`
  ADD CONSTRAINT `inventory_ibfk_1` FOREIGN KEY (`item_id`) REFERENCES `item` (`item_id`),
  ADD CONSTRAINT `inventory_ibfk_2` FOREIGN KEY (`staff_id`) REFERENCES `staff` (`staff_id`);

--
-- Constraints for table `item`
--
ALTER TABLE `item`
  ADD CONSTRAINT `item_ibfk_1` FOREIGN KEY (`staff_id`) REFERENCES `staff` (`staff_id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `order`
--
ALTER TABLE `order`
  ADD CONSTRAINT `order_ibfk_1` FOREIGN KEY (`staff_id`) REFERENCES `staff` (`staff_id`),
  ADD CONSTRAINT `order_ibfk_2` FOREIGN KEY (`supplier_id`) REFERENCES `supplier` (`supplier_id`);

--
-- Constraints for table `order_list`
--
ALTER TABLE `order_list`
  ADD CONSTRAINT `order_list_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `order` (`order_id`),
  ADD CONSTRAINT `order_list_ibfk_2` FOREIGN KEY (`item_id`) REFERENCES `item` (`item_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
