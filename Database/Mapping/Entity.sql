/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('Entity', 'U') IS NOT NULL
  DROP TABLE [Entity];
GO

CREATE TABLE [Entity] (
  [id] INT NOT NULL PRIMARY KEY IDENTITY,
  [typeid] VARCHAR(256) NOT NULL,
  [version] INT NOT NULL);
GO

