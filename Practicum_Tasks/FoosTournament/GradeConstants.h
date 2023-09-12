#pragma once
enum class Grade
{
	Intern = 0,
	JuniorDev,
	MediumDev,
	SeniorDev,
	CTO,
	CEO,
	InvalidGrade = -1
};
static class GradeConstants
{
	static const char* INTERN;
	static const char* CTO;
};
const char* GradeConstants::INTERN = "Intern";
const char* GradeConstants::CTO = "Chief Technical Officer";
