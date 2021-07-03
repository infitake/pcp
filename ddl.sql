create table member(
	memberid varchar(40) NOT NULL PRIMARY KEY,
	familyid varchar(40) NOT NULL,
	ishead boolean NOT NULL,
	firstname varchar(40) NOT NULL,
	lastname varchar(40) NOT NULL,
	suffix varchar(20) NOT NULL,
	gender varchar(20) NOT NULL,
	dob DATE NOT NULL DEFAULT CURRENT_DATE,
	FOREIGN KEY (familyid) REFERENCES family(familyid)
);


CREATE TABLE RELATIONSHIP(
	memberid varchar(40) NOT NULL,
	relation varchar(20) NOT NULL,
	FOREIGN KEY (memberid) REFERENCES member(memberid)
	
);

create table family(
	familyid varchar(40) NOT NULL PRIMARY KEY
);


--ADDING CASCADING ON THE TABLE
-- ON \d table name we will get the description of table
Foreign-key constraints:
    "member_familyid_fkey" FOREIGN KEY (familyid) REFERENCES family(familyid) ON DELETE CASCADE
-- for droping constraints
ALTER TABLE member DROP CONSTRAINT "member_familyid_fkey";
-- for adding cascading
ALTER TABLE member ADD CONSTRAINT "member_familyid_fkey" FOREIGN KEY (familyid) REFERENCES family(familyid) ON DELETE CASCADE ON UPDATE NO ACTION;


-- it will delete the corresponding familyid and also delte the corresponding row in tables in which this acts as a foreign key
DELETE FROM family WHERE familyid = 'qwer125';

-- we can create 3 tables 
-- first having only familyid primay key
-- second having member table in which member id is primary key and familyid is forgein key
-- third define relation ship in which only memberid and relation and memberid is forgein key




