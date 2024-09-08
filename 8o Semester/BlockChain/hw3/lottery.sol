pragma solidity ^0.5.9;

contract lottery
{   
    struct Item{
        uint itemId;
        address[] tokens;} //Each entry corresponds to a bid from the address for the item.

    Item[3] public items;
    address[3] public winners;
    
    //Owners are placed in separate variables because address[] doesnt accept the payable modifier.
    address payable public owner;
    address payable public coOwner;
    
    bool public  prize_draw;

    constructor()public payable
    {
        prize_draw = false;
        owner = msg.sender;
        coOwner = address(0x153dfef4355E823dCB0FCc76Efe942BefCa86477);
        
        address[] memory empty;
        for(uint i=0; i<3; i++){
            items[i] = Item({itemId:i, tokens: empty});
        }
    }
    
    
    function bid(uint itemid) public payable notOwners fixedValue not_prize_draw {
        items[itemid].tokens.push(msg.sender);
    }

    function getNumberOfTokens() public view returns(uint[] memory){
        uint[] memory tokensLength = new uint[](3);
        for(uint i=0; i<3; i++){
            tokensLength[i]=items[i].tokens.length;
        }
        return tokensLength;
    }

    function revealWinners() public onlyOwners not_prize_draw {
        for(uint i=0; i<3; i++){
            if(items[i].tokens.length != 0){
                uint index = random() % items[i].tokens.length;
                winners[i] = items[i].tokens[index];
            }
        }

        prize_draw = true;
    }
    

    //Returns the indexes of the items won by the current account address.
    function getItemsWon() public view notOwners returns (uint[] memory)  {
        uint[] memory _items=new uint[](3);
        require(prize_draw);
        uint _item=0;

        for(uint i=0; i<winners.length;i++)
        {
            if(winners[i]==msg.sender)
            {
                _items[_item]=i;
                _item=_item+1;
            }
        }
        uint[] memory _finalItems=new uint[](_item);
        for(uint i=0; i<_item; i++)
        {
            _finalItems[i]=_items[i];
        }
        return _finalItems;
    }

    function reset() public onlyOwners {
        address[3] memory new_winners;
        winners=new_winners;

        address[] memory empty;
        for(uint i=0; i<3; i++){
            items[i] = Item({itemId:i, tokens: empty});
        }
        
        prize_draw = false;
            
    }
    

    function withdraw() public payable  onlyOwners {
        msg.sender.transfer(address(this).balance);
    }
    
    function random() private view returns(uint){ //Random number generator found on the internet
    return uint(keccak256(abi.encodePacked(block.difficulty, now)));}


    modifier onlyOwners()
    {
        if(!(msg.sender == owner || msg.sender == coOwner)){
            revert();
        }
        _;
    }

    modifier fixedValue(){
        if(!(msg.value == 0.01 ether)){
            revert();
        }
        _;
    }

    modifier notOwners(){
        if(msg.sender == owner || msg.sender == coOwner){
            revert();
        }
        _;
    }

    modifier not_prize_draw(){
        if(prize_draw){
            revert();
        }
        _;
    }

} 