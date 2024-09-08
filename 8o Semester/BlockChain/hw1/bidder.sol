
//address: 0xa8006c5dc92f2a91400cc006849dc75fd6a31779
pragma solidity >=0.5.9;
contract Bidder {
    string public name;
    uint public bidAmount = 20000;
    bool public eligible;
    uint constant minBid = 1000;

    function setName(string memory new_name) public
    {   
        name=new_name;
    }

    function setBitAmount(uint newBidAmount)public
    {
        bidAmount=newBidAmount;
    }

    function determineEligibility() public
    {
        if(bidAmount>=minBid)
        {
            eligible=true;
        }
        else
        {
            eligible=false;
        }
    }

}