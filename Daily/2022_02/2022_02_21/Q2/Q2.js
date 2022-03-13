function createCheckDigit(membershipId) {
  while (membershipId.length !== 1) {
    let ret = 0;
    for (let i = 0; i < membershipId.length; i++) {
      ret += parseInt(membershipId[i]);
    }
    membershipId = String(ret);
    console.log(ret);
  }
  return membershipId;
}

console.log(createCheckDigit("55555"));
