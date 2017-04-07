/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

USE TransportEmpireDB;
GO

IF OBJECT_ID('DBScheduledRace', 'U') IS NOT NULL
  DROP TABLE [DBScheduledRace];
GO

IF OBJECT_ID('DBRace', 'U') IS NOT NULL
  DROP TABLE [DBRace];
GO

IF OBJECT_ID('DBRoute', 'U') IS NOT NULL
  DROP TABLE [DBRoute];
GO

IF OBJECT_ID('DBRouteStatistics', 'U') IS NOT NULL
  DROP TABLE [DBRouteStatistics];
GO

IF OBJECT_ID('DBRaceStatistics', 'U') IS NOT NULL
  DROP TABLE [DBRaceStatistics];
GO

IF OBJECT_ID('DBPath_cities', 'U') IS NOT NULL
  DROP TABLE [DBPath_cities];
GO

IF OBJECT_ID('DBPath', 'U') IS NOT NULL
  DROP TABLE [DBPath];
GO

IF OBJECT_ID('DBCity', 'U') IS NOT NULL
  DROP TABLE [DBCity];
GO

IF OBJECT_ID('DBBus', 'U') IS NOT NULL
  DROP TABLE [DBBus];
GO

IF OBJECT_ID('DBBusState', 'U') IS NOT NULL
  DROP TABLE [DBBusState];
GO

IF OBJECT_ID('DBBusTypeInfo', 'U') IS NOT NULL
  DROP TABLE [DBBusTypeInfo];
GO

CREATE TABLE [DBBusTypeInfo] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [brand] VARCHAR(512) NULL,
  [model] VARCHAR(512) NULL,
  [fuel_consumption] INT NOT NULL,
  [comfort_level] INT NOT NULL);
GO

CREATE TABLE [DBBusState] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [durability] INT NOT NULL,
  [last_technical_inspection_date] DATE NULL,
  [next_technical_inspection_date] DATE NULL,
  [is_avalible] BIT NOT NULL);
GO

CREATE TABLE [DBBus] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [info] BIGINT NOT NULL,
  [state] BIGINT NOT NULL,
  [purchase_date] DATE NULL,
  CONSTRAINT [DBBus_info_fk]
    FOREIGN KEY ([info])
    REFERENCES [DBBusTypeInfo] ([id]),
  CONSTRAINT [DBBus_state_fk]
    FOREIGN KEY ([state])
    REFERENCES [DBBusState] ([id]));
GO

CREATE TABLE [DBCity] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [name] VARCHAR(512) NULL,
  [population] INT NOT NULL,
  [location_x] REAL NOT NULL,
  [location_y] REAL NOT NULL);
GO

CREATE TABLE [DBPath] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [quality_level] INT NOT NULL,
  [milage] FLOAT NOT NULL);
GO

CREATE TABLE [DBPath_cities] (
  [object_id] BIGINT NOT NULL,
  [index] INT NOT NULL,
  [value] BIGINT NULL,
  CONSTRAINT [DBPath_cities_object_id_fk]
    FOREIGN KEY ([object_id])
    REFERENCES [DBPath] ([id])
    ON DELETE CASCADE,
  CONSTRAINT [DBPath_cities_value_fk]
    FOREIGN KEY ([value])
    REFERENCES [DBCity] ([id]));
GO

CREATE INDEX [object_id_i]
  ON [DBPath_cities] ([object_id]);
GO

CREATE INDEX [index_i]
  ON [DBPath_cities] ([index]);
GO

CREATE TABLE [DBRaceStatistics] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [abs_popularity] INT NOT NULL,
  [derivative_popularity] INT NOT NULL,
  [trust_factor] REAL NOT NULL);
GO

CREATE TABLE [DBRouteStatistics] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [quality_factor] REAL NOT NULL,
  [square_coverage] INT NOT NULL,
  [population_coverage] INT NOT NULL);
GO

CREATE TABLE [DBRoute] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [path] BIGINT NULL,
  [statistics] BIGINT NULL,
  [milage] FLOAT NOT NULL,
  CONSTRAINT [DBRoute_path_fk]
    FOREIGN KEY ([path])
    REFERENCES [DBPath] ([id]),
  CONSTRAINT [DBRoute_statistics_fk]
    FOREIGN KEY ([statistics])
    REFERENCES [DBRouteStatistics] ([id]));
GO

CREATE TABLE [DBRace] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [route] BIGINT NULL,
  [bus_type_info] BIGINT NULL,
  [statistics] BIGINT NULL,
  [duration] TIME(3) NULL,
  [expenses_grivnas] INT NOT NULL,
  [expenses_coins] INT NOT NULL,
  [ticket_price_grivnas] INT NOT NULL,
  [ticket_price_coins] INT NOT NULL,
  CONSTRAINT [DBRace_route_fk]
    FOREIGN KEY ([route])
    REFERENCES [DBRoute] ([id]),
  CONSTRAINT [DBRace_bus_type_info_fk]
    FOREIGN KEY ([bus_type_info])
    REFERENCES [DBBusTypeInfo] ([id]),
  CONSTRAINT [DBRace_statistics_fk]
    FOREIGN KEY ([statistics])
    REFERENCES [DBRaceStatistics] ([id]));
GO

CREATE TABLE [DBScheduledRace] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [race] BIGINT NULL,
  [bus] BIGINT NULL,
  [departure_time] TIME(3) NULL,
  [arrival_time] TIME(3) NULL,
  CONSTRAINT [DBScheduledRace_race_fk]
    FOREIGN KEY ([race])
    REFERENCES [DBRace] ([id]),
  CONSTRAINT [DBScheduledRace_bus_fk]
    FOREIGN KEY ([bus])
    REFERENCES [DBBus] ([id]));
GO
