INSERT INTO family(familyid) VALUES('qwer123');
INSERT INTO family(familyid) VALUES('qwer124');
INSERT INTO family(familyid) VALUES('qwer125');


INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem1qwer123','qwer123',true,'raj','kumar','mr','male','12/3/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem2qwer123','qwer123',false,'kavi','kumar','mr','male','13/1/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem3qwer123','qwer123',false,'rani','chal','mrs','female','3/4/1998');


INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem1qwer124','qwer124',true,'pawan','kumar','mr','male','4/6/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem2qwer124','qwer124',false,'pk','kumar','mr','male','12/7/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem3qwer124','qwer124',false,'pani','rani','mrs','female','2/3/1998');

INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem1qwer125','qwer125',true,'raja','kumar','mr','male','12/1/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem2qwer125','qwer125',false,'dk','kumar','mr','male','12/6/1998');
INSERT INTO member(memberid,familyid,ishead,firstname,lastname,suffix,gender,dob) VALUES('mem3qwer125','qwer125',false,'bv','kumar','mr','male','12/5/1998');


INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem2qwer123','father');
INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem3qwer123','wife');

INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem2qwer124','father');
INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem3qwer124','mother');

INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem2qwer125','father');
INSERT INTO RELATIONSHIP(memberid,relation) VALUES('mem3qwer125','daughter');
